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

	//--Find a suitable skeleton root--//

	//create a list of nodes that have an influence or this TriBasedGeom
	//as decendents
	list<NiAVObjectRef> ancestors;

	NiAVObjectRef shape_tree_top = ListAncestors( StaticCast<NiAVObject>(this), ancestors );
	NiAVObjectRef bone_tree_top;

	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
		bone_tree_top = ListAncestors( StaticCast<NiAVObject>(bone_nodes[i]), ancestors );
		//Make sure bone and shapre are part of the same tree
		if ( bone_tree_top != shape_tree_top ) {
			throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
		}
	}

	NiNodeRef skeleton_root = FindFirstCommonAncestor( shape_tree_top, ancestors );

	//Create a skin instance using the bone and root data
	skinInstance = new NiSkinInstance( skeleton_root, bone_nodes );

	//Create a NiSkinData object based on this mesh
	skinInstance->SetSkinData( new NiSkinData( this ) );
};

Ref<NiAVObject> NiTriBasedGeom::ListAncestors( const Ref<NiAVObject> & leaf, list< Ref<NiAVObject> > & ancestors ) const {
	NiAVObjectRef avObj = leaf;
	while ( avObj->GetParent() != NULL ) {
		ancestors.push_back(avObj);
		avObj = avObj->GetParent();
	}

	//Return top of tree
	return avObj;
}

Ref<NiNode> NiTriBasedGeom::FindFirstCommonAncestor( const Ref<NiAVObject> & avObj, const list< Ref<NiAVObject> > & ancestors ) const {
	//See if we've found the common ancestor yet
	for ( list<NiAVObjectRef>::const_iterator ancestor = ancestors.begin(); ancestor != ancestors.end(); ++ancestor ) {
		if ( *ancestor == avObj ) {
			//We found the common ancestor, return it.
			return DynamicCast<NiNode>(avObj);
		}
	}
	
	//Call this function on any children
	NiNodeRef niNode = DynamicCast<NiNode>(avObj);
	if ( niNode != NULL ) {
		vector<NiAVObjectRef> children = niNode->GetChildren();
		for ( uint i = 0; i < children.size(); ++i ) {
			return FindFirstCommonAncestor( children[i], ancestors );
		}
	} else {
		return NULL;
	}
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