/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBoolData.h"

//Definition of TYPE constant
const Type NiBoolData::TYPE("NiBoolData", &NI_BOOL_DATA_PARENT::TYPE );

NiBoolData::NiBoolData() NI_BOOL_DATA_CONSTRUCT {}

NiBoolData::~NiBoolData() {}

void NiBoolData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_BOOL_DATA_READ
}

void NiBoolData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_BOOL_DATA_WRITE
}

string NiBoolData::asString( bool verbose ) const {
	NI_BOOL_DATA_STRING
}

void NiBoolData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_BOOL_DATA_FIXLINKS
}

