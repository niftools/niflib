/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "hkPackedNiTriStripsData.h"

//Definition of TYPE constant
const Type hkPackedNiTriStripsData::TYPE("hkPackedNiTriStripsData", &HK_PACKED_NI_TRI_STRIPS_DATA_PARENT::TYPE );

hkPackedNiTriStripsData::hkPackedNiTriStripsData() HK_PACKED_NI_TRI_STRIPS_DATA_CONSTRUCT {}

hkPackedNiTriStripsData::~hkPackedNiTriStripsData() {}

void hkPackedNiTriStripsData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	HK_PACKED_NI_TRI_STRIPS_DATA_READ
}

void hkPackedNiTriStripsData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	HK_PACKED_NI_TRI_STRIPS_DATA_WRITE
}

string hkPackedNiTriStripsData::asString( bool verbose ) const {
	HK_PACKED_NI_TRI_STRIPS_DATA_STRING
}

void hkPackedNiTriStripsData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	HK_PACKED_NI_TRI_STRIPS_DATA_FIXLINKS
}

