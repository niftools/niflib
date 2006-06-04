/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysData.h"

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NI_P_SYS_DATA_PARENT::TYPE );

NiPSysData::NiPSysData() NI_P_SYS_DATA_CONSTRUCT {}

NiPSysData::~NiPSysData() {}

void NiPSysData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_DATA_READ
}

void NiPSysData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_DATA_WRITE
}

string NiPSysData::asString( bool verbose ) const {
	NI_P_SYS_DATA_STRING
}

void NiPSysData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_DATA_FIXLINKS
}

list<NiObjectRef> NiPSysData::GetRefs() const {
	NI_P_SYS_DATA_GETREFS
}

const Type & NiPSysData::GetType() const {
	return TYPE;
};

