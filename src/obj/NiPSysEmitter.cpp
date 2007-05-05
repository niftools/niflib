/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitter::TYPE("NiPSysEmitter", &NI_P_SYS_EMITTER_PARENT::TYPE );

NiPSysEmitter::NiPSysEmitter() NI_P_SYS_EMITTER_CONSTRUCT {}

NiPSysEmitter::~NiPSysEmitter() {}

void NiPSysEmitter::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitter::GetType() const {
	return TYPE;
};
