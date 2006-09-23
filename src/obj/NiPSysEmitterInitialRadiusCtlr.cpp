/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterInitialRadiusCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterInitialRadiusCtlr::TYPE("NiPSysEmitterInitialRadiusCtlr", &NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENT::TypeConst() );

NiPSysEmitterInitialRadiusCtlr::NiPSysEmitterInitialRadiusCtlr() NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT {}

NiPSysEmitterInitialRadiusCtlr::~NiPSysEmitterInitialRadiusCtlr() {}

void NiPSysEmitterInitialRadiusCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitterInitialRadiusCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitterInitialRadiusCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterInitialRadiusCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitterInitialRadiusCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterInitialRadiusCtlr::GetType() const {
	return TYPE;
};

