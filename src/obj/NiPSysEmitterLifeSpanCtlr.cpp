/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterLifeSpanCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterLifeSpanCtlr::TYPE("NiPSysEmitterLifeSpanCtlr", &NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT::TypeConst() );

NiPSysEmitterLifeSpanCtlr::NiPSysEmitterLifeSpanCtlr() NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT {}

NiPSysEmitterLifeSpanCtlr::~NiPSysEmitterLifeSpanCtlr() {}

void NiPSysEmitterLifeSpanCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_READ
}

void NiPSysEmitterLifeSpanCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_WRITE
}

string NiPSysEmitterLifeSpanCtlr::asString( bool verbose ) const {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_STRING
}

void NiPSysEmitterLifeSpanCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_FIXLINKS
}

list<NiObjectRef> NiPSysEmitterLifeSpanCtlr::GetRefs() const {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_GETREFS
}

const Type & NiPSysEmitterLifeSpanCtlr::GetType() const {
	return TYPE;
};

