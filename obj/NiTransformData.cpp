/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTransformData.h"

//Definition of TYPE constant
const Type NiTransformData::TYPE("NiTransformData", &NI_TRANSFORM_DATA_PARENT::TYPE );

NiTransformData::NiTransformData() NI_TRANSFORM_DATA_CONSTRUCT {}

NiTransformData::~NiTransformData() {}

void NiTransformData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_TRANSFORM_DATA_READ
}

void NiTransformData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TRANSFORM_DATA_WRITE
}

string NiTransformData::asString( bool verbose ) const {
	NI_TRANSFORM_DATA_STRING
}

void NiTransformData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_TRANSFORM_DATA_FIXLINKS
}

