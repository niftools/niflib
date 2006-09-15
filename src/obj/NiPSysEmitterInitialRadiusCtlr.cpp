/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterInitialRadiusCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterInitialRadiusCtlr::TYPE("NiPSysEmitterInitialRadiusCtlr", &NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENT::TypeConst() );

NiPSysEmitterInitialRadiusCtlr::NiPSysEmitterInitialRadiusCtlr() NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT {}

NiPSysEmitterInitialRadiusCtlr::~NiPSysEmitterInitialRadiusCtlr() {}

void NiPSysEmitterInitialRadiusCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_READ
}

void NiPSysEmitterInitialRadiusCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_WRITE
}

string NiPSysEmitterInitialRadiusCtlr::asString( bool verbose ) const {
	NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_STRING
}

void NiPSysEmitterInitialRadiusCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_FIXLINKS
}

list<NiObjectRef> NiPSysEmitterInitialRadiusCtlr::GetRefs() const {
	NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_GETREFS
}

const Type & NiPSysEmitterInitialRadiusCtlr::GetType() const {
	return TYPE;
};

