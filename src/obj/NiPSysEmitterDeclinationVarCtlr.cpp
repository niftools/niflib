/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterDeclinationVarCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterDeclinationVarCtlr::TYPE("NiPSysEmitterDeclinationVarCtlr", &NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT::TypeConst() );

NiPSysEmitterDeclinationVarCtlr::NiPSysEmitterDeclinationVarCtlr() NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_CONSTRUCT {}

NiPSysEmitterDeclinationVarCtlr::~NiPSysEmitterDeclinationVarCtlr() {}

void NiPSysEmitterDeclinationVarCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitterDeclinationVarCtlr::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitterDeclinationVarCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterDeclinationVarCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitterDeclinationVarCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterDeclinationVarCtlr::GetType() const {
	return TYPE;
};

