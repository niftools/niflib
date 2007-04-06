/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterDeclinationVarCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterDeclinationVarCtlr::TYPE("NiPSysEmitterDeclinationVarCtlr", &NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT::TypeConst() );

NiPSysEmitterDeclinationVarCtlr::NiPSysEmitterDeclinationVarCtlr() NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_CONSTRUCT {}

NiPSysEmitterDeclinationVarCtlr::~NiPSysEmitterDeclinationVarCtlr() {}

void NiPSysEmitterDeclinationVarCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterDeclinationVarCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterDeclinationVarCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterDeclinationVarCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitterDeclinationVarCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterDeclinationVarCtlr::GetType() const {
	return TYPE;
};

const Type & NiPSysEmitterDeclinationVarCtlr::TypeConst() {
	return TYPE;
}
