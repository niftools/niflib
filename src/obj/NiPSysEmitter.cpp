/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitter::TYPE("NiPSysEmitter", &NI_P_SYS_EMITTER_PARENT::TypeConst() );

NiPSysEmitter::NiPSysEmitter() NI_P_SYS_EMITTER_CONSTRUCT {}

NiPSysEmitter::~NiPSysEmitter() {}

void NiPSysEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitter::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitter::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitter::GetType() const {
	return TYPE;
};

