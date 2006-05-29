/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFloatData.h"

//Definition of TYPE constant
const Type NiFloatData::TYPE("NiFloatData", &NI_FLOAT_DATA_PARENT::TYPE );

NiFloatData::NiFloatData() NI_FLOAT_DATA_CONSTRUCT {}

NiFloatData::~NiFloatData() {}

void NiFloatData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_FLOAT_DATA_READ
}

void NiFloatData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_FLOAT_DATA_WRITE
}

string NiFloatData::asString( bool verbose ) const {
	NI_FLOAT_DATA_STRING
}

void NiFloatData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_FLOAT_DATA_FIXLINKS
}

