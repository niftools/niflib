/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSPSysArrayEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSPSysArrayEmitter::TYPE("BSPSysArrayEmitter", &B_S_P_SYS_ARRAY_EMITTER_PARENT::TypeConst() );

BSPSysArrayEmitter::BSPSysArrayEmitter() B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT {}

BSPSysArrayEmitter::~BSPSysArrayEmitter() {}

void BSPSysArrayEmitter::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void BSPSysArrayEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string BSPSysArrayEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSPSysArrayEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> BSPSysArrayEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSPSysArrayEmitter::GetType() const {
	return TYPE;
};

const Type & BSPSysArrayEmitter::TypeConst() {
	return TYPE;
}
