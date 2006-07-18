/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriBasedGeom.h"
#include "NiTriBasedGeomData.h"
#include "NiSkinInstance.h"
#include "NiObject.h"
#include "NiSkinData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriBasedGeom::TYPE("NiTriBasedGeom", &NI_TRI_BASED_GEOM_PARENT::TypeConst() );

NiTriBasedGeom::NiTriBasedGeom() NI_TRI_BASED_GEOM_CONSTRUCT {}

NiTriBasedGeom::~NiTriBasedGeom() {}

void NiTriBasedGeom::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_BASED_GEOM_READ
}

void NiTriBasedGeom::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRI_BASED_GEOM_WRITE
}

string NiTriBasedGeom::asString( bool verbose ) const {
	NI_TRI_BASED_GEOM_STRING
}

void NiTriBasedGeom::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_BASED_GEOM_FIXLINKS
}

list<NiObjectRef> NiTriBasedGeom::GetRefs() const {
	NI_TRI_BASED_GEOM_GETREFS
}

const Type & NiTriBasedGeom::GetType() const {
	return TYPE;
};

Ref<NiTriBasedGeomData> NiTriBasedGeom::GetData() const {
	return data;
}

void NiTriBasedGeom::SetData( const Ref<NiTriBasedGeomData> & n ) {
	data = n;
}

Ref<NiObject> NiTriBasedGeom::GetUnknownLink() const {
	return unknownLink;
}

void NiTriBasedGeom::SetUnknownLink( const Ref<NiObject> & n ) {
	unknownLink = n;
}

string NiTriBasedGeom::GetShader() const {
	return shaderName;
}

void NiTriBasedGeom::SetShader( const string & n ) {
	//Check if name is blank, if so clear shader
	if ( n.size() == 0 ) {
		hasShader = false;
		shaderName.clear();
	} else {
		shaderName = n;
	}
}

Ref<NiSkinInstance> NiTriBasedGeom::GetSkinInstance() const {
	return skinInstance;
}

void NiTriBasedGeom::BindSkin( vector< Ref<NiNode> > bone_nodes ) {
	//Ensure skin is not aleady bound
	if ( skinInstance != 0 ) {
		throw runtime_error("You have attempted to re-bind a skin that is already bound.  Unbind it first.");
	}

	//Ensure that some bones are given
	if ( bone_nodes.size() == 0 ) {
		throw runtime_error("You must specify at least one bone node.");
	}

	//--Find a suitable skeleton root--//

	//create lists of nodes that have an influence and this TriBasedGeom
	//as decendents
	int num_lists = int(bone_nodes.size()) + 1;
	vector< list<NiNodeRef> > ancestors( num_lists );

	if ( GetParent() == NULL ) {
		throw runtime_error("Attempted to bind skin on a shape with no parent.");
	}

	ancestors[bone_nodes.size()] = ListAncestors( GetParent() );
	
	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
		NiNodeRef bonePar = bone_nodes[i]->GetParent();
		if ( bonePar == NULL ) {
			throw runtime_error("Attempted to bind skin to a bone with no parent.  A skeleton root cannot be a bone so all bones must have at least one parent.");
		}
		ancestors[i] = ListAncestors( bonePar );
	}

	if ( ancestors[0].size() == 0 ) {
		throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
	}

	NiNodeRef skeleton_root = ancestors[0].front();
	//Make sure bone and shapes are part of the same tree
	for ( int i = 1; i < num_lists; ++i ) {
		if ( ancestors[i].size() == 0 ) {
			throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
		}
		if ( ancestors[i].front() != skeleton_root ) {
			throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
		}
	}

	//Since the first items have been shown to match, pop all the stacks
	for ( int i = 0; i < num_lists; ++i ) {
		ancestors[i].pop_front();
	}

	//Now search for the common ancestor

	while(true) {
		bool all_same = true;
		if ( ancestors[0].size() == 0 ) {
			//This list is over, so the last top is the common ancestor
			//break out of the loop
			break;
		}
		NiNodeRef first_ancestor = ancestors[0].front();
		for ( int i = 1; i < num_lists; ++i ) {
			if ( ancestors[i].size() == 0 ) {
				//This list is over, so the last top is the common ancestor
				//break out of the loop
				all_same = false;
				break;
			}
			if ( ancestors[i].front() != first_ancestor ) {
				all_same = false;
			}
		}

		if ( all_same == true ) {
			//They're all the same, so set the top, pop all the stacks
			//and look again
			
			skeleton_root = ancestors[0].front();
			for ( int i = 0; i < num_lists; ++i ) {
				ancestors[i].pop_front();
			}
		} else {
			//One is different, so the last top is the common ancestor.
			//break out of the loop
			break;
		}
	}

	if ( skeleton_root == NULL ) {
		throw runtime_error("Failed to find suitable skeleton root.");
	}

	//Create a skin instance using the bone and root data
	skinInstance = new NiSkinInstance( skeleton_root, bone_nodes );

	//Create a NiSkinData object based on this mesh
	skinInstance->SetSkinData( new NiSkinData( this ) );
};

list< Ref<NiNode> > NiTriBasedGeom::ListAncestors( const Ref<NiNode> & leaf ) const {
	if ( leaf == NULL ) {
		throw runtime_error("ListAncestors called with a NULL leaf NiNode Ref");
	}
	
	list<NiNodeRef> ancestors;

	NiNodeRef niNode = leaf;
	while (true) {
		ancestors.push_front(niNode);
		if ( niNode->GetParent() == NULL ) {
			break;
		} else {
			niNode = niNode->GetParent();
		}
	}

	return ancestors;
}

void NiTriBasedGeom::UnbindSkin() {
	//Clear skin instance
	skinInstance = NULL;
}

vector<Vector3> NiTriBasedGeom::GetSkinInfluencedVertices() const {
	//--Get required data & insure validity--//

	NiTriBasedGeomDataRef geom_data = GetData();

	if ( geom_data == NULL ) {
		throw runtime_error("This NiTriBasedGeom has no NiTriBasedGeomData so there are no vertices to get.");
	}

	NiSkinInstanceRef skin_inst = GetSkinInstance();
	

	if ( skin_inst == NULL ) {
		throw runtime_error("This NiTriBasedGeom is not influenced by a skin.");
	}

	NiSkinDataRef skin_data = skin_inst->GetSkinData();

	if ( skin_data == NULL ) {
		throw runtime_error("Skin Data is missing, cannot calculate skin influenced vertex position.");
	}

	//Ensure that skin instance bone count & skin data bone count match
	if ( skin_inst->GetBoneCount() != skin_data->GetBoneCount() ) {
		throw runtime_error("Skin Instance and Skin Data bone count do not match.");
	}

	//Get skeleton root
	NiNodeRef skel_root = skin_inst->GetSkeletonRoot();
	if ( skel_root == NULL ) {
		throw runtime_error("Skin Instance is not bound to a skeleton root.");
	}

	//Get the vertices & bone nodes
	vector<Vector3> vertices = geom_data->GetVertices();
	vector<NiNodeRef> bone_nodes = skin_inst->GetBones();

	//Set up an aray to hold the transformed vertices
	vector<Vector3> skin_verts( vertices.size());

	//Transform vertices into position based on skin data
	Matrix44 root_world = skel_root->GetWorldTransform();
	Matrix44 geom_world = GetWorldTransform();
	for ( uint i = 0; i < skin_data->GetBoneCount(); ++i ) {
		Matrix44 bone_world = bone_nodes[i]->GetWorldTransform();
		Matrix44 bone_offset = skin_data->GetBoneTransform(i);
		vector<SkinWeight> weights = skin_data->GetBoneWeights(i);
		Matrix44 vert_trans =  bone_offset * bone_world;
		for ( uint j = 0; j < weights.size(); ++j ) {
			uint index = weights[j].index;
			float weight = weights[j].weight;
			skin_verts[index] += (vert_trans * vertices[index] ) * weight;
		}
	}

	//Transform all vertices to final position
	for ( uint i = 0; i < skin_verts.size(); ++i ) {
		skin_verts[i] = geom_world.Inverse() * skin_verts[i];
	}

	return skin_verts;
}