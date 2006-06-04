/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiFloatExtraData.h"

//Definition of TYPE constant
const Type NiFloatExtraData::TYPE("NiFloatExtraData", &NI_FLOAT_EXTRA_DATA_PARENT::TYPE );

NiFloatExtraData::NiFloatExtraData() NI_FLOAT_EXTRA_DATA_CONSTRUCT {}

NiFloatExtraData::~NiFloatExtraData() {}

void NiFloatExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOAT_EXTRA_DATA_READ
}

void NiFloatExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_FLOAT_EXTRA_DATA_WRITE
}

string NiFloatExtraData::asString( bool verbose ) const {
	NI_FLOAT_EXTRA_DATA_STRING
}

void NiFloatExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOAT_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiFloatExtraData::GetRefs() const {
	NI_FLOAT_EXTRA_DATA_GETREFS
}

const Type & NiFloatExtraData::GetType() const {
	return TYPE;
};

