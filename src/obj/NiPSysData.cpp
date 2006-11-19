/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NI_P_SYS_DATA_PARENT::TypeConst() );

NiPSysData::NiPSysData() NI_P_SYS_DATA_CONSTRUCT {}

NiPSysData::~NiPSysData() {}

void NiPSysData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysData::GetType() const {
	return TYPE;
};

