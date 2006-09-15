/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type APSysData::TYPE("APSysData", &A_P_SYS_DATA_PARENT::TypeConst() );

APSysData::APSysData() A_P_SYS_DATA_CONSTRUCT {}

APSysData::~APSysData() {}

void APSysData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	A_P_SYS_DATA_READ
}

void APSysData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	A_P_SYS_DATA_WRITE
}

string APSysData::asString( bool verbose ) const {
	A_P_SYS_DATA_STRING
}

void APSysData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	A_P_SYS_DATA_FIXLINKS
}

list<NiObjectRef> APSysData::GetRefs() const {
	A_P_SYS_DATA_GETREFS
}

const Type & APSysData::GetType() const {
	return TYPE;
};

