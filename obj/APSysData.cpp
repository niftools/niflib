/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysData.h"

//Definition of TYPE constant
const Type APSysData::TYPE("APSysData", &A_P_SYS_DATA_PARENT::TYPE );

APSysData::APSysData() A_P_SYS_DATA_CONSTRUCT {}

APSysData::~APSysData() {}

void APSysData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	A_P_SYS_DATA_READ
}

string APSysData::asString( bool verbose ) const {
	A_P_SYS_DATA_STRING
}

void APSysData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	A_P_SYS_DATA_FIXLINKS
}
