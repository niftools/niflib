/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysEmitterLifeSpanCtlr.h"

//Definition of TYPE constant
const Type NiPSysEmitterLifeSpanCtlr::TYPE("NiPSysEmitterLifeSpanCtlr", &NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT::TYPE );

NiPSysEmitterLifeSpanCtlr::NiPSysEmitterLifeSpanCtlr() NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT {}

NiPSysEmitterLifeSpanCtlr::~NiPSysEmitterLifeSpanCtlr() {}

void NiPSysEmitterLifeSpanCtlr::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_READ
}

void NiPSysEmitterLifeSpanCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_WRITE
}

string NiPSysEmitterLifeSpanCtlr::asString( bool verbose ) const {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_STRING
}

void NiPSysEmitterLifeSpanCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_FIXLINKS
}

