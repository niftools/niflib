/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiNode.h"
#include "NiAVObject.h"
#include "NiDynamicEffect.h"
#include "NiSkinInstance.h"
#include "NiSkinData.h"
#include "NiTriBasedGeom.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiNode::TYPE("NiNode", &NI_NODE_PARENT::TypeConst() );

NiNode::NiNode() NI_NODE_CONSTRUCT {
	//Set flag to default of 8: not a skin influence
	flags = 8;
}

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

void NiNode::AddChild( Ref<NiAVObject> obj ) {
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


void NiNode::AddEffect( Ref<NiDynamicEffect> obj ) {
   obj->SetParent( this );
   effects.push_back( obj );
}

void NiNode::RemoveEffect( Ref<NiDynamicEffect> obj ) {
   //Search Effect list for the one to remove
   for ( vector< NiDynamicEffectRef >::iterator it = effects.begin(); it != effects.end(); ) {
      if ( *it == obj ) {
         (*it)->SetParent(NULL);
         it = effects.erase( it );
      } else {
         ++it;
      }
   }
}

void NiNode::ClearEffects() {
   for ( vector< NiDynamicEffectRef >::iterator it = effects.begin(); it != effects.end(); ++it) {
      if (*it) (*it)->SetParent(NULL);
   }
   effects.clear();
}

vector< Ref<NiDynamicEffect> > NiNode::GetEffects() const {
   return effects;
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
		vector<NiNodeRef> bone_nodes = (*it)->GetBones();
		NiSkinDataRef skin_data = (*it)->GetSkinData();

		if ( skin_data == NULL ) {
			//There's no skin data for this skin instance; skip it.
			continue;
		}

		//Make sure the counts match
		if ( bone_nodes.size() != skin_data->GetBoneCount() ) {
			throw runtime_error( "Bone counts in NiSkinInstance and attached NiSkinData must match" );
		}

		//Loop through all bones influencing this skin
		for ( uint i = 0; i < bone_nodes.size(); ++i ) {
			//Get current offset Matrix for this bone
			Matrix44 parent_offset = skin_data->GetBoneTransform(i);

			//Loop through all bones again, checking for any that have this bone as a parent
			for ( uint j = 0; j < bone_nodes.size(); ++j ) {
				if ( bone_nodes[j]->GetParent() == bone_nodes[i] ) {
					//cout << "Bone " << bones[j] << " has bone " << bones[i] << " as parent." << endl;
					//Node 2 has node 1 as a parent

					//Get child offset Matrix33
					Matrix44 child_offset = skin_data->GetBoneTransform(j);

					//Do calculation to get correct bone postion in relation to parent
					Matrix44 child_pos = child_offset.Inverse() * parent_offset;

					//bones[j]->SetWorldBindPos( child_pos );
					bone_nodes[j]->SetLocalRotation( child_pos.GetRotation() );
					bone_nodes[j]->SetLocalScale( 1.0f );
					bone_nodes[j]->SetLocalTranslation( child_pos.GetTranslation() );
				}
			}
		}
	}
}

bool NiNode::IsSplitMeshProxy() const {
	//Let us guess that a node is a split mesh proxy if:
	// 1)  All its children are NiTriBasedGeom derived objects.
	// 2)  All its children have identity transforms.
	// 3)  It has more than one child
	// 4)  All meshes are visible
	// 5)  ????  May need more criteria as time goes on.

	if ( children.size() < 2 ) {
		return false;
	}

	for ( unsigned i = 0; i < children.size(); ++i ) {
		if ( children[i]->IsDerivedType( NiTriBasedGeom::TypeConst() ) == false ) {
			return false;
		}
		if ( children[i]->GetLocalTransform() != Matrix44::IDENTITY ) {
			return false;
		}
		if ( children[i]->GetVisibility() == false ) {
			return false;
		}
	}

	//Made it all the way through the loop without returning false
	return true;
}