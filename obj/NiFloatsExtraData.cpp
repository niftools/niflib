/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFloatsExtraData.h"

//Definition of TYPE constant
const Type NiFloatsExtraData::TYPE("NiFloatsExtraData", &NI_FLOATS_EXTRA_DATA_PARENT::TYPE );

NiFloatsExtraData::NiFloatsExtraData() NI_FLOATS_EXTRA_DATA_CONSTRUCT {}

NiFloatsExtraData::~NiFloatsExtraData() {}

void NiFloatsExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOATS_EXTRA_DATA_READ
}

void NiFloatsExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_FLOATS_EXTRA_DATA_WRITE
}

string NiFloatsExtraData::asString( bool verbose ) const {
	NI_FLOATS_EXTRA_DATA_STRING
}

void NiFloatsExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOATS_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiFloatsExtraData::GetRefs() const {
	NI_FLOATS_EXTRA_DATA_GETREFS
}

const Type & NiFloatsExtraData::GetType() const {
	return TYPE;
};

