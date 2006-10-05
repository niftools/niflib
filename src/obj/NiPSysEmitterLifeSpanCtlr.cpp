/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterLifeSpanCtlr.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterLifeSpanCtlr::TYPE("NiPSysEmitterLifeSpanCtlr", &NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT::TypeConst() );

NiPSysEmitterLifeSpanCtlr::NiPSysEmitterLifeSpanCtlr() NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT {}

NiPSysEmitterLifeSpanCtlr::~NiPSysEmitterLifeSpanCtlr() {}

void NiPSysEmitterLifeSpanCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitterLifeSpanCtlr::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitterLifeSpanCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterLifeSpanCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitterLifeSpanCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterLifeSpanCtlr::GetType() const {
	return TYPE;
};

