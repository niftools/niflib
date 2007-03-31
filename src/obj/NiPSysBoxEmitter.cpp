/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysBoxEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysBoxEmitter::TYPE("NiPSysBoxEmitter", &NI_P_SYS_BOX_EMITTER_PARENT::TypeConst() );

NiPSysBoxEmitter::NiPSysBoxEmitter() NI_P_SYS_BOX_EMITTER_CONSTRUCT {}

NiPSysBoxEmitter::~NiPSysBoxEmitter() {}

void NiPSysBoxEmitter::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysBoxEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysBoxEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysBoxEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysBoxEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysBoxEmitter::GetType() const {
	return TYPE;
};

const Type & NiPSysBoxEmitter::TypeConst() {
	return TYPE;
}
