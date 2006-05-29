/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiStringExtraData.h"

//Definition of TYPE constant
const Type NiStringExtraData::TYPE("NiStringExtraData", &NI_STRING_EXTRA_DATA_PARENT::TYPE );

NiStringExtraData::NiStringExtraData() NI_STRING_EXTRA_DATA_CONSTRUCT {}

NiStringExtraData::~NiStringExtraData() {}

void NiStringExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_STRING_EXTRA_DATA_READ
}

void NiStringExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_STRING_EXTRA_DATA_WRITE
}

string NiStringExtraData::asString( bool verbose ) const {
	NI_STRING_EXTRA_DATA_STRING
}

void NiStringExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_STRING_EXTRA_DATA_FIXLINKS
}

uint NiStringExtraData::BytesRemaining() const { return 0; };

