/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStringsExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringsExtraData::TYPE("NiStringsExtraData", &NI_STRINGS_EXTRA_DATA_PARENT::TypeConst() );

NiStringsExtraData::NiStringsExtraData() NI_STRINGS_EXTRA_DATA_CONSTRUCT {}

NiStringsExtraData::~NiStringsExtraData() {}

void NiStringsExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiStringsExtraData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiStringsExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStringsExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiStringsExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiStringsExtraData::GetType() const {
	return TYPE;
};

vector<string> NiStringsExtraData::GetData() const {
	return data;
};
	
void NiStringsExtraData::SetData( const vector<string> & n ) {
	numStrings = uint(n.size());
	data = n;
};
