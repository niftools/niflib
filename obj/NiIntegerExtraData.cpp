/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiIntegerExtraData.h"

//Definition of TYPE constant
const Type NiIntegerExtraData::TYPE("NiIntegerExtraData", &NI_INTEGER_EXTRA_DATA_PARENT::TypeConst() );

NiIntegerExtraData::NiIntegerExtraData() NI_INTEGER_EXTRA_DATA_CONSTRUCT {}

NiIntegerExtraData::~NiIntegerExtraData() {}

void NiIntegerExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_INTEGER_EXTRA_DATA_READ
}

void NiIntegerExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_INTEGER_EXTRA_DATA_WRITE
}

string NiIntegerExtraData::asString( bool verbose ) const {
	NI_INTEGER_EXTRA_DATA_STRING
}

void NiIntegerExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_INTEGER_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiIntegerExtraData::GetRefs() const {
	NI_INTEGER_EXTRA_DATA_GETREFS
}

const Type & NiIntegerExtraData::GetType() const {
	return TYPE;
};

