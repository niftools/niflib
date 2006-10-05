/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatExtraData::TYPE("NiFloatExtraData", &NI_FLOAT_EXTRA_DATA_PARENT::TypeConst() );

NiFloatExtraData::NiFloatExtraData() NI_FLOAT_EXTRA_DATA_CONSTRUCT {}

NiFloatExtraData::~NiFloatExtraData() {}

void NiFloatExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiFloatExtraData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiFloatExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiFloatExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatExtraData::GetType() const {
	return TYPE;
};

float NiFloatExtraData::GetData() const {
	return floatData;
}
	
void NiFloatExtraData::SetData( float n ) {
	floatData = n;
}