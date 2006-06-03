/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiIntegersExtraData.h"

//Definition of TYPE constant
const Type NiIntegersExtraData::TYPE("NiIntegersExtraData", &NI_INTEGERS_EXTRA_DATA_PARENT::TYPE );

NiIntegersExtraData::NiIntegersExtraData() NI_INTEGERS_EXTRA_DATA_CONSTRUCT {}

NiIntegersExtraData::~NiIntegersExtraData() {}

void NiIntegersExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_INTEGERS_EXTRA_DATA_READ
}

void NiIntegersExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_INTEGERS_EXTRA_DATA_WRITE
}

string NiIntegersExtraData::asString( bool verbose ) const {
	NI_INTEGERS_EXTRA_DATA_STRING
}

void NiIntegersExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_INTEGERS_EXTRA_DATA_FIXLINKS
}

const Type & NiIntegersExtraData::GetType() const {
	return TYPE;
};

