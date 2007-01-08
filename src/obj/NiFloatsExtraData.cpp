/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatsExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatsExtraData::TYPE("NiFloatsExtraData", &NI_FLOATS_EXTRA_DATA_PARENT::TypeConst() );

NiFloatsExtraData::NiFloatsExtraData() NI_FLOATS_EXTRA_DATA_CONSTRUCT {}

NiFloatsExtraData::~NiFloatsExtraData() {}

void NiFloatsExtraData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiFloatsExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiFloatsExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatsExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiFloatsExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatsExtraData::GetType() const {
	return TYPE;
};

vector<float> NiFloatsExtraData::GetData() const {
	return data;
}
	
void NiFloatsExtraData::SetData( const vector<float> & n ) {
	numFloats = (unsigned int)(n.size());
	data = n;
}
