/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysResetOnLoopCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysResetOnLoopCtlr::TYPE("NiPSysResetOnLoopCtlr", &NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT::TypeConst() );

NiPSysResetOnLoopCtlr::NiPSysResetOnLoopCtlr() NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT {}

NiPSysResetOnLoopCtlr::~NiPSysResetOnLoopCtlr() {}

void NiPSysResetOnLoopCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysResetOnLoopCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysResetOnLoopCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysResetOnLoopCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysResetOnLoopCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysResetOnLoopCtlr::GetType() const {
	return TYPE;
};

const Type & NiPSysResetOnLoopCtlr::TypeConst() {
	return TYPE;
}
