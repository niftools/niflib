/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSPSysArrayEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSPSysArrayEmitter::TYPE("BSPSysArrayEmitter", &B_S_P_SYS_ARRAY_EMITTER_PARENT::TypeConst() );

BSPSysArrayEmitter::BSPSysArrayEmitter() B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT {}

BSPSysArrayEmitter::~BSPSysArrayEmitter() {}

void BSPSysArrayEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	B_S_P_SYS_ARRAY_EMITTER_READ
}

void BSPSysArrayEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	B_S_P_SYS_ARRAY_EMITTER_WRITE
}

string BSPSysArrayEmitter::asString( bool verbose ) const {
	B_S_P_SYS_ARRAY_EMITTER_STRING
}

void BSPSysArrayEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	B_S_P_SYS_ARRAY_EMITTER_FIXLINKS
}

list<NiObjectRef> BSPSysArrayEmitter::GetRefs() const {
	B_S_P_SYS_ARRAY_EMITTER_GETREFS
}

const Type & BSPSysArrayEmitter::GetType() const {
	return TYPE;
};

