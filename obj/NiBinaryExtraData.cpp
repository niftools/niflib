/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBinaryExtraData.h"
#include "../gen/ByteArray.h"

//Definition of TYPE constant
const Type NiBinaryExtraData::TYPE("NiBinaryExtraData", &NI_BINARY_EXTRA_DATA_PARENT::TypeConst() );

NiBinaryExtraData::NiBinaryExtraData() NI_BINARY_EXTRA_DATA_CONSTRUCT {}

NiBinaryExtraData::~NiBinaryExtraData() {}

void NiBinaryExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BINARY_EXTRA_DATA_READ
}

void NiBinaryExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BINARY_EXTRA_DATA_WRITE
}

string NiBinaryExtraData::asString( bool verbose ) const {
	NI_BINARY_EXTRA_DATA_STRING
}

void NiBinaryExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BINARY_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiBinaryExtraData::GetRefs() const {
	NI_BINARY_EXTRA_DATA_GETREFS
}

const Type & NiBinaryExtraData::GetType() const {
	return TYPE;
};

