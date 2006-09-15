/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysResetOnLoopCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysResetOnLoopCtlr::TYPE("NiPSysResetOnLoopCtlr", &NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT::TypeConst() );

NiPSysResetOnLoopCtlr::NiPSysResetOnLoopCtlr() NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT {}

NiPSysResetOnLoopCtlr::~NiPSysResetOnLoopCtlr() {}

void NiPSysResetOnLoopCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_RESET_ON_LOOP_CTLR_READ
}

void NiPSysResetOnLoopCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_RESET_ON_LOOP_CTLR_WRITE
}

string NiPSysResetOnLoopCtlr::asString( bool verbose ) const {
	NI_P_SYS_RESET_ON_LOOP_CTLR_STRING
}

void NiPSysResetOnLoopCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_RESET_ON_LOOP_CTLR_FIXLINKS
}

list<NiObjectRef> NiPSysResetOnLoopCtlr::GetRefs() const {
	NI_P_SYS_RESET_ON_LOOP_CTLR_GETREFS
}

const Type & NiPSysResetOnLoopCtlr::GetType() const {
	return TYPE;
};

