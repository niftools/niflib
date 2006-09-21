/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStringExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringExtraData::TYPE("NiStringExtraData", &NI_STRING_EXTRA_DATA_PARENT::TypeConst() );

NiStringExtraData::NiStringExtraData() NI_STRING_EXTRA_DATA_CONSTRUCT {}

NiStringExtraData::~NiStringExtraData() {}

void NiStringExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STRING_EXTRA_DATA_READ
}

void NiStringExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_STRING_EXTRA_DATA_WRITE
}

string NiStringExtraData::asString( bool verbose ) const {
	NI_STRING_EXTRA_DATA_STRING
}

void NiStringExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STRING_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiStringExtraData::GetRefs() const {
	NI_STRING_EXTRA_DATA_GETREFS
}

const Type & NiStringExtraData::GetType() const {
	return TYPE;
};

string NiStringExtraData::GetData() const {
	return stringData;
}

void NiStringExtraData::SetData( const string & n ) {
	stringData = n;
	bytesRemaining = uint(stringData.size()) + 4;
}