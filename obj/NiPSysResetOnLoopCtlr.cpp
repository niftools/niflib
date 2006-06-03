/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysResetOnLoopCtlr.h"

//Definition of TYPE constant
const Type NiPSysResetOnLoopCtlr::TYPE("NiPSysResetOnLoopCtlr", &NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT::TYPE );

NiPSysResetOnLoopCtlr::NiPSysResetOnLoopCtlr() NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT {}

NiPSysResetOnLoopCtlr::~NiPSysResetOnLoopCtlr() {}

void NiPSysResetOnLoopCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_RESET_ON_LOOP_CTLR_READ
}

void NiPSysResetOnLoopCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_RESET_ON_LOOP_CTLR_WRITE
}

string NiPSysResetOnLoopCtlr::asString( bool verbose ) const {
	NI_P_SYS_RESET_ON_LOOP_CTLR_STRING
}

void NiPSysResetOnLoopCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_RESET_ON_LOOP_CTLR_FIXLINKS
}

const Type & NiPSysResetOnLoopCtlr::GetType() const {
	return TYPE;
};

