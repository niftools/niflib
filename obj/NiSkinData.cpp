/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSkinData.h"
#include "../gen/SkinData.h"
#include "../gen/SkinWeight.h"
#include "NiSkinPartition.h"
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

void NiSkinData::SetBoneData( const vector<SkinData> & n ) {
	boneList = n;
}

vector<SkinData> NiSkinData::GetBoneData() const {
	return boneList;
}

void NiSkinData::SetOverallTransform( const Matrix44 & n ) {
	translation = n.GetTranslation();
	rotation = n.GetRotation();
	Vector3 s = n.GetScale();
	scale = s.x + s.y + s.z / 3.0f;
}
	
Matrix44 NiSkinData::GetOverallTransform() const {
	return Matrix44( translation, rotation, scale );
}