/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterDeclinationCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterDeclinationCtlr::TYPE("NiPSysEmitterDeclinationCtlr", &NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT::TypeConst() );

NiPSysEmitterDeclinationCtlr::NiPSysEmitterDeclinationCtlr() NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT {}

NiPSysEmitterDeclinationCtlr::~NiPSysEmitterDeclinationCtlr() {}

void NiPSysEmitterDeclinationCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterDeclinationCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterDeclinationCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterDeclinationCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitterDeclinationCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterDeclinationCtlr::GetType() const {
	return TYPE;
};

const Type & NiPSysEmitterDeclinationCtlr::TypeConst() {
	return TYPE;
}
