/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSkinData.h"
#include "../gen/SkinData.h"
#include "../gen/SkinWeight.h"
#include "NiSkinPartition.h"
#include "NiTriBasedGeom.h"
#include "NiSkinInstance.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinData::TYPE("NiSkinData", &NI_SKIN_DATA_PARENT::TypeConst() );

NiSkinData::NiSkinData() NI_SKIN_DATA_CONSTRUCT {}

NiSkinData::~NiSkinData() {}

void NiSkinData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SKIN_DATA_READ
}

void NiSkinData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SKIN_DATA_WRITE
}

string NiSkinData::asString( bool verbose ) const {
	NI_SKIN_DATA_STRING
}

void NiSkinData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SKIN_DATA_FIXLINKS
}

list<NiObjectRef> NiSkinData::GetRefs() const {
	NI_SKIN_DATA_GETREFS
}

const Type & NiSkinData::GetType() const {
	return TYPE;
};

uint NiSkinData::GetBoneCount() const {
	return uint( boneList.size() );
}

Matrix44 NiSkinData::GetBoneTransform( uint bone_index ) const {
	if ( bone_index > boneList.size() ) {
		throw runtime_error( "The specified bone index was larger than the number of bones in this NiSkinData." );
	}

	return Matrix44( boneList[bone_index].translation, boneList[bone_index].rotation, boneList[bone_index].scale );
}

vector<SkinWeight> NiSkinData::GetBoneWeights( uint bone_index ) const {
	if ( bone_index > boneList.size() ) {
		throw runtime_error( "The specified bone index was larger than the number of bones in this NiSkinData." );
	}

	return boneList[bone_index].vertexWeights;
}

void NiSkinData::SetBoneWeights( uint bone_index, const vector<SkinWeight> & n ) {
	if ( bone_index > boneList.size() ) {
		throw runtime_error( "The specified bone index was larger than the number of bones in this NiSkinData." );
	}

	boneList[bone_index].vertexWeights = n;
}

Matrix44 NiSkinData::GetOverallTransform() const {
	return Matrix44( translation, rotation, scale );
}

NiSkinData::NiSkinData( const Ref<NiTriBasedGeom> & owner ) {
	//Get skin instance
	NiSkinInstanceRef skinInst = owner->GetSkinInstance();

	if ( skinInst == NULL ) {
		throw runtime_error("Skin instance should have already been created.");
	}

	boneList.resize( skinInst->GetBoneCount() );
	vector<NiNodeRef> bone_nodes = skinInst->GetBones();
	
	//--Calculate Overall Offset--//

	//Get TriBasedGeom world transform
	Matrix44 owner_mat = owner->GetWorldTransform();

	//Get Skeleton root world transform
	Matrix44 skel_root_mat = skinInst->GetSkeletonRoot()->GetWorldTransform();

	//Inverse owner NiTriBasedGeom matrix & multiply with skeleton root matrix
	Matrix44 res_mat = owner_mat.Inverse() * skel_root_mat;

	//Store result
	res_mat.Decompose( translation, rotation, scale );

	//--Calculate Bone Offsets--//

	Matrix44 bone_mat;
	for (uint i = 0; i < boneList.size(); ++i ) {
		//--Get Bone Bind Pose--//

		//Get bone world position
		bone_mat = bone_nodes[i]->GetWorldTransform();

		//Multiply NiTriBasedGeom matrix with inversed bone matrix
		res_mat = owner_mat * bone_mat.Inverse();

		//Store result
		res_mat.Decompose( boneList[i].translation, boneList[i].rotation, boneList[i].scale );

		//TODO:  Calculate center and radius of each bone
	}
}