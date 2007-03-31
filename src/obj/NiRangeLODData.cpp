/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiRangeLODData.h"
#include "../../include/gen/LODRange.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRangeLODData::TYPE("NiRangeLODData", &NI_RANGE_L_O_D_DATA_PARENT::TypeConst() );

NiRangeLODData::NiRangeLODData() NI_RANGE_L_O_D_DATA_CONSTRUCT {}

NiRangeLODData::~NiRangeLODData() {}

void NiRangeLODData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiRangeLODData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiRangeLODData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiRangeLODData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiRangeLODData::GetRefs() const {
	return InternalGetRefs();
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

const Type & NiRangeLODData::TypeConst() {
	return TYPE;
}
