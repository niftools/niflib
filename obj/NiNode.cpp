/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiNode.h"
#include "NiAVObject.h"
#include "NiDynamicEffect.h"
#include "NiSkinInstance.h"
#include "NiSkinData.h"
#include "NiTriBasedGeom.h"

//Definition of TYPE constant
const Type NiNode::TYPE("NiNode", &NI_NODE_PARENT::TypeConst() );

NiNode::NiNode() NI_NODE_CONSTRUCT {}

NiNode::~NiNode() {
	//Clear Children
	ClearChildren();

	//Unbind any attached skins
	for ( list<NiSkinInstance*>::iterator it = skins.begin(); it != skins.end(); ++it ) {
		(*it)->SkeletonLost();
	}
}

void NiNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_NODE_READ
}

void NiNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_NODE_WRITE
}

string NiNode::asString( bool verbose ) const {
	NI_NODE_STRING
}

void NiNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_NODE_FIXLINKS
	//Connect children to their parents and remove any NULL ones
	for ( vector< NiAVObjectRef >::iterator it = children.begin(); it != children.end(); ) {
		if ( *it == NULL) {
			it = children.erase( it );
		} else {
			(*it)->SetParent(this);
			++it;
		}
	}
}

list<NiObjectRef> NiNode::GetRefs() const {
	NI_NODE_GETREFS
}

const Type & NiNode::GetType() const {
	return TYPE;
};

void NiNode::AddChild( Ref<NiAVObject> & obj ) {
	if ( obj->GetParent() != NULL ) {
		throw runtime_error( "You have attempted to add a child to a NiNode which already is the child of another NiNode." );
	}
	obj->SetParent( this );
	children.push_back( obj );
}

void NiNode::RemoveChild( Ref<NiAVObject> obj ) {
	//Search child list for the one to remove
	for ( vector< NiAVObjectRef >::iterator it = children.begin(); it != children.end(); ) {
		if ( *it == obj ) {
			//Ensure that this child is not a skin influence
			NiNodeRef niNode = DynamicCast<NiNode>((*it));
			if ( niNode != NULL && niNode->IsSkinInfluence() == true ) {
				throw runtime_error("You cannot remove a node child that is a skin influence.  Detatch the skin first.");
			}
			(*it)->SetParent(NULL);
			it = children.erase( it );
		} else {
			++it;
		}
	}
}

void NiNode::ClearChildren() {
	for ( vector< NiAVObjectRef >::iterator it = children.begin(); it != children.end(); ++it) {
      if (*it) (*it)->SetParent(NULL);
	}
	children.clear();
}

vector< Ref<NiAVObject> > NiNode::GetChildren() const {
	return children;
}

bool NiNode::IsSkeletonRoot() const {
	return ( skins.size() > 0 );
}

bool NiNode::IsSkinInfluence() const {
	return ((flags & 8) == 0);
}

void NiNode::AddSkin( NiSkinInstance * skin_inst ) {
	skins.push_back( skin_inst );
}

void NiNode::RemoveSkin( NiSkinInstance * skin_inst ) {
	//Unflag any bones that were part of this skin instance
	vector<NiNodeRef> bones = skin_inst->GetBones();
	for ( uint i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(false);
	}
	
	//Remove the reference
	skins.remove( skin_inst);

	//Ensure that any multiply referenced bone nodes still
	//have their skin flag set
	for ( list<NiSkinInstance*>::iterator it = skins.begin(); it != skins.end(); ++it ) {
		bones = (*it)->GetBones();
		for ( uint i = 0; i < bones.size(); ++i ) {
			bones[i]->SetSkinFlag(true);
		}
	}
}

void NiNode::SetSkinFlag( bool n ) {
	if ( IsSkinInfluence() == n ) {
		//Already set to the requested value
		return;
	} else {
		//Requested value is different, flip bit
		flags ^= 8;
	}
}

void NiNode::GoToSkeletonBindPosition() {
	//map<NiNodeRef, Matrix44> world_positions;
	
	//Loop through all attached skins, straightening the skeleton on each
	for ( list<NiSkinInstance*>::iterator it = skins.begin(); it != skins.end(); ++it ) {
		//Get Bone list and Skin Data
		vector<NiNodeRef> bones = (*it)->GetBones();
		NiSkinDataRef skin_data = (*it)->GetSkinData();

		if ( skin_data == NULL ) {
			//There's no skin data for this skin instance; skip it.
			continue;
		}

		//Get bone data from NiSkinData class
		vector<SkinData> bone_data = skin_data->GetBoneData();

		//Make sure the counts match
		if ( bones.size() != bone_data.size() ) {
			throw runtime_error( "Bone counts in NiSkinInstance and attached NiSkinData must match" );
		}

		//Loop through all bones influencing this skin
		for ( uint i = 0; i < bones.size(); ++i ) {
			//Get current offset Matrix for this bone
			//Matrix44 parent_offset( bone_data[i].translation,
			//	                    bone_data[i].rotation,
			//						bone_data[i].scale );
			Matrix44 parent_offset(
				bone_data[i].rotation[0][0], bone_data[i].rotation[0][1], bone_data[i].rotation[0][2], 0.0f,
				bone_data[i].rotation[1][0], bone_data[i].rotation[1][1], bone_data[i].rotation[1][2], 0.0f,
				bone_data[i].rotation[2][0], bone_data[i].rotation[2][1], bone_data[i].rotation[2][2], 0.0f,
				bone_data[i].translation.x, bone_data[i].translation.y, bone_data[i].translation.z, 1.0f
			); 

			//Loop through all bones again, checking for any that have this bone as a parent
			for ( uint j = 0; j < bones.size(); ++j ) {
				if ( bones[j]->GetParent() == bones[i] ) {
					//cout << "Bone " << bones[j] << " has bone " << bones[i] << " as parent." << endl;
					//Node 2 has node 1 as a parent

					//Get child offset Matrix33
					/*Matrix44 child_offset( bone_data[j].translation,
										   bone_data[j].rotation,
										   bone_data[j].scale );*/
					Matrix44 child_offset(
						bone_data[j].rotation[0][0], bone_data[j].rotation[0][1], bone_data[j].rotation[0][2], 0.0f,
						bone_data[j].rotation[1][0], bone_data[j].rotation[1][1], bone_data[j].rotation[1][2], 0.0f,
						bone_data[j].rotation[2][0], bone_data[j].rotation[2][1], bone_data[j].rotation[2][2], 0.0f,
						bone_data[j].translation.x, bone_data[j].translation.y, bone_data[j].translation.z, 1.0f
					);

					//Do calculation to get correct bone postion in relation to parent
					//Matrix44 inverse_co = child_offset.Inverse();
					//world_positions[bones[j]] = inverse_co * parent_offset;
					Matrix44 inverse_co = child_offset.Inverse();
					Matrix44 child_pos = inverse_co * parent_offset;

					//bones[j]->SetWorldBindPos( child_pos );
					bones[j]->SetLocalRotation( child_pos.GetRotation() );
					bones[j]->SetLocalScale( 1.0f );
					bones[j]->SetLocalTranslation( child_pos.GetTranslation() );

					//cout << "Matrix:  " << cout << "Translation:  " << world_positions[bones[j]] << endl;
					//cout << "Translation:  " << world_positions[bones[j]].GetTranslation() << endl;
					//cout << "Rotation:  " << world_positions[bones[j]].GetRotation() << endl;
					//cout << "Scale:  " << world_positions[bones[j]].GetScale() << endl;
				}
			}
		}
	}

	//Search for any NiTriBasedGeom classes lower in the scene graph and
	//reposition them
	RepositionGeom(this);
}

void NiNode::RepositionGeom( NiAVObjectRef root ) {
	//Check if this is a NiTriBasedGeom
	NiTriBasedGeomRef geom = DynamicCast<NiTriBasedGeom>(root);

	if ( geom != NULL ) {
		//This is a NiTriBasedGeom class
		//Get NiSkinInstance and NiSkinData

		NiSkinInstanceRef skin_inst = geom->GetSkinInstance();

		if ( skin_inst == NULL ) {
			return;
		}

		NiSkinDataRef skin_data = skin_inst->GetSkinData();

		if ( skin_data == NULL ) {
			return;
		}

		//Get bone info
		vector<NiNodeRef> bones = skin_inst->GetBones();
		vector<SkinData> bone_data = skin_data->GetBoneData();

		//Make sure the counts match
		if ( bones.size() != bone_data.size() ) {
			throw runtime_error( "Bone counts in NiSkinInstance and attached NiSkinData must match" );
		}

		//There must be at least one bone to do anything
		if ( bones.size() == 0 ) {
			return;
		}

		//Use first bone (arbitrary choice)
		Matrix44 offset_mat(
			bone_data[0].rotation[0][0], bone_data[0].rotation[0][1], bone_data[0].rotation[0][2], 0.0f,
			bone_data[0].rotation[1][0], bone_data[0].rotation[1][1], bone_data[0].rotation[1][2], 0.0f,
			bone_data[0].rotation[2][0], bone_data[0].rotation[2][1], bone_data[0].rotation[2][2], 0.0f,
			bone_data[0].translation.x, bone_data[0].translation.y, bone_data[0].translation.z, 1.0f
		);
			
		//Get built up rotations to the root of the skeleton from this bone
		Matrix44 bone_mat = bones[0]->GetWorldTransform();

		Matrix44 world_mat = offset_mat * bone_mat;

		Matrix44 result_mat = world_mat * geom->GetParent()->GetWorldTransform().Inverse();

		//--Set TriShape Local Position to Result--//
		geom->SetLocalRotation( result_mat.GetRotation() );
		geom->SetLocalTranslation( result_mat.GetTranslation() );
		geom->SetLocalScale( 1.0f );

		//TODO: Calculate the correct adjustment for the NiSkinData overall matrix
		//due to this change

		return;
	}

	//Check if this is a NiNode
	NiNodeRef node = DynamicCast<NiNode>(root);
	
	if ( node != NULL ) {
		//This is a NiNode, call this function on all children
		vector<NiAVObjectRef> children = node->GetChildren();
		for ( uint i = 0; i < children.size(); ++i ) {
			RepositionGeom( children[i] );
		}
	}
}