/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NI_P_SYS_DATA_PARENT::TypeConst() );

NiPSysData::NiPSysData() NI_P_SYS_DATA_CONSTRUCT {}

NiPSysData::~NiPSysData() {}

void NiPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysData::GetType() const {
	return TYPE;
};

const Type & NiPSysData::TypeConst() {
	return TYPE;
}
