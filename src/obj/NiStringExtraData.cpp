/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStringExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringExtraData::TYPE("NiStringExtraData", &NI_STRING_EXTRA_DATA_PARENT::TypeConst() );

NiStringExtraData::NiStringExtraData() NI_STRING_EXTRA_DATA_CONSTRUCT {}

NiStringExtraData::~NiStringExtraData() {}

void NiStringExtraData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiStringExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiStringExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStringExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiStringExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiStringExtraData::GetType() const {
	return TYPE;
};

string NiStringExtraData::GetData() const {
	return stringData;
}

void NiStringExtraData::SetData( const string & n ) {
	stringData = n;
	bytesRemaining = unsigned int(stringData.size()) + 4;
}
