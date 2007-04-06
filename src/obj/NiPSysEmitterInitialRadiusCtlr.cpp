/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterInitialRadiusCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterInitialRadiusCtlr::TYPE("NiPSysEmitterInitialRadiusCtlr", &NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENT::TypeConst() );

NiPSysEmitterInitialRadiusCtlr::NiPSysEmitterInitialRadiusCtlr() NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT {}

NiPSysEmitterInitialRadiusCtlr::~NiPSysEmitterInitialRadiusCtlr() {}

void NiPSysEmitterInitialRadiusCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterInitialRadiusCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterInitialRadiusCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterInitialRadiusCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitterInitialRadiusCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterInitialRadiusCtlr::GetType() const {
	return TYPE;
};

const Type & NiPSysEmitterInitialRadiusCtlr::TypeConst() {
	return TYPE;
}
