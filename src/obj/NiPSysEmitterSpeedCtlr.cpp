/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterSpeedCtlr.h"
#include "../../include/obj/NiFloatData.h"

using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterSpeedCtlr::TYPE("NiPSysEmitterSpeedCtlr", &NI_P_SYS_EMITTER_SPEED_CTLR_PARENT::TYPE );

NiPSysEmitterSpeedCtlr::NiPSysEmitterSpeedCtlr() NI_P_SYS_EMITTER_SPEED_CTLR_CONSTRUCT {}

NiPSysEmitterSpeedCtlr::~NiPSysEmitterSpeedCtlr() {}

void NiPSysEmitterSpeedCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterSpeedCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterSpeedCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterSpeedCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitterSpeedCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterSpeedCtlr::GetType() const {
	return TYPE;
};
