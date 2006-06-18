/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysUpdateCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysUpdateCtlr::TYPE("NiPSysUpdateCtlr", &NI_P_SYS_UPDATE_CTLR_PARENT::TypeConst() );

NiPSysUpdateCtlr::NiPSysUpdateCtlr() NI_P_SYS_UPDATE_CTLR_CONSTRUCT {}

NiPSysUpdateCtlr::~NiPSysUpdateCtlr() {}

void NiPSysUpdateCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_UPDATE_CTLR_READ
}

void NiPSysUpdateCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_UPDATE_CTLR_WRITE
}

string NiPSysUpdateCtlr::asString( bool verbose ) const {
	NI_P_SYS_UPDATE_CTLR_STRING
}

void NiPSysUpdateCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_UPDATE_CTLR_FIXLINKS
}

list<NiObjectRef> NiPSysUpdateCtlr::GetRefs() const {
	NI_P_SYS_UPDATE_CTLR_GETREFS
}

const Type & NiPSysUpdateCtlr::GetType() const {
	return TYPE;
};

