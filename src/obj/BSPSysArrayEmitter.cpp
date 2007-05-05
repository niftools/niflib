/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSPSysArrayEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSPSysArrayEmitter::TYPE("BSPSysArrayEmitter", &B_S_P_SYS_ARRAY_EMITTER_PARENT::TYPE );

BSPSysArrayEmitter::BSPSysArrayEmitter() B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT {}

BSPSysArrayEmitter::~BSPSysArrayEmitter() {}

void BSPSysArrayEmitter::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void BSPSysArrayEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string BSPSysArrayEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSPSysArrayEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> BSPSysArrayEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSPSysArrayEmitter::GetType() const {
	return TYPE;
};
