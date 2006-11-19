/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterDeclinationCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterDeclinationCtlr::TYPE("NiPSysEmitterDeclinationCtlr", &NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT::TypeConst() );

NiPSysEmitterDeclinationCtlr::NiPSysEmitterDeclinationCtlr() NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT {}

NiPSysEmitterDeclinationCtlr::~NiPSysEmitterDeclinationCtlr() {}

void NiPSysEmitterDeclinationCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitterDeclinationCtlr::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitterDeclinationCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterDeclinationCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitterDeclinationCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterDeclinationCtlr::GetType() const {
	return TYPE;
};

