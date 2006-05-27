/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiColorExtraData.h"

//Definition of TYPE constant
const Type NiColorExtraData::TYPE("NiColorExtraData", &NI_COLOR_EXTRA_DATA_PARENT::TYPE );

NiColorExtraData::NiColorExtraData() NI_COLOR_EXTRA_DATA_CONSTRUCT {}

NiColorExtraData::~NiColorExtraData() {}

void NiColorExtraData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_COLOR_EXTRA_DATA_READ
}

void NiColorExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_COLOR_EXTRA_DATA_WRITE
}

string NiColorExtraData::asString( bool verbose ) const {
	NI_COLOR_EXTRA_DATA_STRING
}

void NiColorExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_COLOR_EXTRA_DATA_FIXLINKS
}

