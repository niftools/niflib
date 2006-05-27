/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriStripsData.h"

//Definition of TYPE constant
const Type NiTriStripsData::TYPE("NiTriStripsData", &NI_TRI_STRIPS_DATA_PARENT::TYPE );

NiTriStripsData::NiTriStripsData() NI_TRI_STRIPS_DATA_CONSTRUCT {}

NiTriStripsData::~NiTriStripsData() {}

void NiTriStripsData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_TRI_STRIPS_DATA_READ
}

void NiTriStripsData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TRI_STRIPS_DATA_WRITE
}

string NiTriStripsData::asString( bool verbose ) const {
	NI_TRI_STRIPS_DATA_STRING
}

void NiTriStripsData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_TRI_STRIPS_DATA_FIXLINKS
}

