/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiStringsExtraData.h"

//Definition of TYPE constant
const Type NiStringsExtraData::TYPE("NiStringsExtraData", &NI_STRINGS_EXTRA_DATA_PARENT::TYPE );

NiStringsExtraData::NiStringsExtraData() NI_STRINGS_EXTRA_DATA_CONSTRUCT {}

NiStringsExtraData::~NiStringsExtraData() {}

void NiStringsExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STRINGS_EXTRA_DATA_READ
}

void NiStringsExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_STRINGS_EXTRA_DATA_WRITE
}

string NiStringsExtraData::asString( bool verbose ) const {
	NI_STRINGS_EXTRA_DATA_STRING
}

void NiStringsExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STRINGS_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiStringsExtraData::GetRefs() const {
	NI_STRINGS_EXTRA_DATA_GETREFS
}

const Type & NiStringsExtraData::GetType() const {
	return TYPE;
};

