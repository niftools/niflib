/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysResetOnLoopCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysResetOnLoopCtlr::TYPE("NiPSysResetOnLoopCtlr", &NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT::TypeConst() );

NiPSysResetOnLoopCtlr::NiPSysResetOnLoopCtlr() NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT {}

NiPSysResetOnLoopCtlr::~NiPSysResetOnLoopCtlr() {}

void NiPSysResetOnLoopCtlr::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysResetOnLoopCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysResetOnLoopCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysResetOnLoopCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysResetOnLoopCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysResetOnLoopCtlr::GetType() const {
	return TYPE;
};

