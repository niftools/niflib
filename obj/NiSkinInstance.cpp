/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSkinInstance.h"
#include "NiNode.h"
#include "NiSkinData.h"
#include "NiSkinPartition.h"
#include "NiNode.h"

//Definition of TYPE constant
const Type NiSkinInstance::TYPE("NiSkinInstance", &NI_SKIN_INSTANCE_PARENT::TYPE );

NiSkinInstance::NiSkinInstance() NI_SKIN_INSTANCE_CONSTRUCT {}

NiSkinInstance::~NiSkinInstance() {}

void NiSkinInstance::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SKIN_INSTANCE_READ
}

void NiSkinInstance::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SKIN_INSTANCE_WRITE
}

string NiSkinInstance::asString( bool verbose ) const {
	NI_SKIN_INSTANCE_STRING
}

void NiSkinInstance::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SKIN_INSTANCE_FIXLINKS

	//Inform newly fixed skeleton root of attachment
	if ( skeletonRoot != NULL ) {
		skeletonRoot->AddSkin( this );
	}
}

list<NiObjectRef> NiSkinInstance::GetRefs() const {
	NI_SKIN_INSTANCE_GETREFS
}

const Type & NiSkinInstance::GetType() const {
	return TYPE;
};

vector< Ref<NiNode> > NiSkinInstance::GetBones() const {
	vector<NiNodeRef> ref_bones( bones.size() );
	for (uint i = 0; i < bones.size(); ++i ) {
		ref_bones[i] = bones[i];
	}
	return ref_bones;
}

void NiSkinInstance::Bind( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes ) {
	//Ensure skin is not aleady bound
	if ( bones.size() != 0 ) {
		throw runtime_error("You have attempted to re-bind a skin that is already bound.  Unbind it first.");
	}

	//Ensure that all bones are below the skeleton root node on the scene graph
	for ( uint i = 0; i < bone_nodes.size(); ++i ) {
		bool is_decended = false;
		NiNodeRef node = bone_nodes[i];
		while ( node != NULL ) {
			if ( node == skeleton_root ) {
				is_decended = true;
				break;
			}
			node = node->GetParent();
		}
		if ( is_decended == false ) {
			throw runtime_error( "All bones must be lower than the skeleton root in the scene graph." );
		}
	}

	//Add the bones to the internal list
	bones.resize( bone_nodes.size() );
	for ( uint i = 0; i < bone_nodes.size(); ++i ) {
		bones[i] = bone_nodes[i];
	}

	//Flag any bones that are part of this skin instance
	for ( uint i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}

	//Store skeleton root and inform it of this attachment
	skeletonRoot = skeleton_root;
	skeletonRoot->AddSkin( this );
};

void NiSkinInstance::Unbind() {
	//Inform Skeleton Root of detatchment and clear it.
	skeletonRoot->RemoveSkin( this );
	skeletonRoot = NULL;

	//Clear bone list
	bones.clear();

	//Destroy skin data
	data = NULL;
	skinPartition = NULL;
}

void NiSkinInstance::CalcHardwareSkinningData () {

}

Ref<NiSkinData> NiSkinInstance::GetSkinData() const {
	return data;
}

void NiSkinInstance::SetSkinData( const Ref<NiSkinData> & n ) {
	data = n;
}

Ref<NiSkinPartition> NiSkinInstance::GetSkinPartition() const {
	return skinPartition;
}

void NiSkinInstance::SetSkinPartition( const Ref<NiSkinPartition> & n ) {
	skinPartition = n;
}

void NiSkinInstance::SkeletonLost() {
	skeletonRoot = NULL;

	//Clear bone list
	bones.clear();

	//Destroy skin data
	data = NULL;
	skinPartition = NULL;
}