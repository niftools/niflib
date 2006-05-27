/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysEmitter.h"

//Definition of TYPE constant
const Type APSysEmitter::TYPE("APSysEmitter", &A_P_SYS_EMITTER_PARENT::TYPE );

APSysEmitter::APSysEmitter() A_P_SYS_EMITTER_CONSTRUCT {}

APSysEmitter::~APSysEmitter() {}

void APSysEmitter::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	A_P_SYS_EMITTER_READ
}

void APSysEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_P_SYS_EMITTER_WRITE
}

string APSysEmitter::asString( bool verbose ) const {
	A_P_SYS_EMITTER_STRING
}

void APSysEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	A_P_SYS_EMITTER_FIXLINKS
}

