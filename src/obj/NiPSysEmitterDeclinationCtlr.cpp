/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterDeclinationCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterDeclinationCtlr::TYPE("NiPSysEmitterDeclinationCtlr", &NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT::TypeConst() );

NiPSysEmitterDeclinationCtlr::NiPSysEmitterDeclinationCtlr() NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT {}

NiPSysEmitterDeclinationCtlr::~NiPSysEmitterDeclinationCtlr() {}

void NiPSysEmitterDeclinationCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_DECLINATION_CTLR_READ
}

void NiPSysEmitterDeclinationCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_EMITTER_DECLINATION_CTLR_WRITE
}

string NiPSysEmitterDeclinationCtlr::asString( bool verbose ) const {
	NI_P_SYS_EMITTER_DECLINATION_CTLR_STRING
}

void NiPSysEmitterDeclinationCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_DECLINATION_CTLR_FIXLINKS
}

list<NiObjectRef> NiPSysEmitterDeclinationCtlr::GetRefs() const {
	NI_P_SYS_EMITTER_DECLINATION_CTLR_GETREFS
}

const Type & NiPSysEmitterDeclinationCtlr::GetType() const {
	return TYPE;
};

