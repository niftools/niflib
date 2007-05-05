/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterLifeSpanCtlr.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterLifeSpanCtlr::TYPE("NiPSysEmitterLifeSpanCtlr", &NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT::TYPE );

NiPSysEmitterLifeSpanCtlr::NiPSysEmitterLifeSpanCtlr() NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT {}

NiPSysEmitterLifeSpanCtlr::~NiPSysEmitterLifeSpanCtlr() {}

void NiPSysEmitterLifeSpanCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterLifeSpanCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterLifeSpanCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterLifeSpanCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitterLifeSpanCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterLifeSpanCtlr::GetType() const {
	return TYPE;
};
