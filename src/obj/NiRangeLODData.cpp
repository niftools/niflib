/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiRangeLODData.h"
#include "../../include/gen/LODRange.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRangeLODData::TYPE("NiRangeLODData", &NI_RANGE_L_O_D_DATA_PARENT::TypeConst() );

NiRangeLODData::NiRangeLODData() NI_RANGE_L_O_D_DATA_CONSTRUCT {}

NiRangeLODData::~NiRangeLODData() {}

void NiRangeLODData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_RANGE_L_O_D_DATA_READ
}

void NiRangeLODData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_RANGE_L_O_D_DATA_WRITE
}

string NiRangeLODData::asString( bool verbose ) const {
	NI_RANGE_L_O_D_DATA_STRING
}

void NiRangeLODData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_RANGE_L_O_D_DATA_FIXLINKS
}

list<NiObjectRef> NiRangeLODData::GetRefs() const {
	NI_RANGE_L_O_D_DATA_GETREFS
}

const Type & NiRangeLODData::GetType() const {
	return TYPE;
};

Vector3 NiRangeLODData::GetLODCenter() const {
	return lodCenter;
}

void NiRangeLODData::SetLODCenter( const Vector3 & value ) {
	lodCenter = value;
}

vector<LODRange > NiRangeLODData::GetLODLevels() const {
	return lodLevels;
}

void NiRangeLODData::SetLODLevels( const vector<LODRange >& value ) {
	lodLevels = value;
}

