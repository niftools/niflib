/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiSkinData.h"
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinInstance::TYPE("NiSkinInstance", &NI_SKIN_INSTANCE_PARENT::TypeConst() );

NiSkinInstance::NiSkinInstance() NI_SKIN_INSTANCE_CONSTRUCT {}

NiSkinInstance::NiSkinInstance( NiNode * skeleton_root, vector< Ref<NiNode> > bone_nodes ) NI_SKIN_INSTANCE_CONSTRUCT {
	//Ensure that all bones are below the skeleton root node on the scene graph
	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
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
	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
		bones[i] = bone_nodes[i];
	}

	//Flag any bones that are part of this skin instance
	for ( unsigned int i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}

	//Store skeleton root and inform it of this attachment
	skeletonRoot = skeleton_root;
	skeletonRoot->AddSkin( this );
}

NiSkinInstance::~NiSkinInstance() {
	//Unflag any bones that were part of this skin instance
	for ( unsigned int i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(false);
	}

	//Inform Skeleton Root of detatchment and clear it.
	if ( skeletonRoot != NULL ) {
		skeletonRoot->RemoveSkin( this );
		skeletonRoot = NULL;
	}
}

void NiSkinInstance::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSkinInstance::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSkinInstance::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSkinInstance::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );

	//Inform newly fixed skeleton root of attachment
	if ( skeletonRoot != NULL ) {
		skeletonRoot->AddSkin( this );
	}

	//Ensure that bones have the flag set properly
	for ( unsigned int i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}
}

list<NiObjectRef> NiSkinInstance::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSkinInstance::GetType() const {
	return TYPE;
};

vector< Ref<NiNode> > NiSkinInstance::GetBones() const {
	vector<NiNodeRef> ref_bones( bones.size() );
	for (unsigned int i = 0; i < bones.size(); ++i ) {
		ref_bones[i] = bones[i];
	}
	return ref_bones;
}

Ref<NiSkinData> NiSkinInstance::GetSkinData() const {
	return data;
}

void NiSkinInstance::SetSkinData( NiSkinData * n ) {
	data = n;
}

Ref<NiSkinPartition> NiSkinInstance::GetSkinPartition() const {
	return skinPartition;
}

void NiSkinInstance::SetSkinPartition( NiSkinPartition * n ) {
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

unsigned int NiSkinInstance::GetBoneCount() const {
	return (unsigned int)(bones.size());
}

Ref<NiNode> NiSkinInstance::GetSkeletonRoot() const {
	return skeletonRoot;
}

const Type & NiSkinInstance::TypeConst() {
	return TYPE;
}
