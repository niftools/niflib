/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysBoxEmitter.h"

//Definition of TYPE constant
const Type NiPSysBoxEmitter::TYPE("NiPSysBoxEmitter", &NI_P_SYS_BOX_EMITTER_PARENT::TYPE );

NiPSysBoxEmitter::NiPSysBoxEmitter() NI_P_SYS_BOX_EMITTER_CONSTRUCT {}

NiPSysBoxEmitter::~NiPSysBoxEmitter() {}

void NiPSysBoxEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_BOX_EMITTER_READ
}

void NiPSysBoxEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_BOX_EMITTER_WRITE
}

string NiPSysBoxEmitter::asString( bool verbose ) const {
	NI_P_SYS_BOX_EMITTER_STRING
}

void NiPSysBoxEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_BOX_EMITTER_FIXLINKS
}

const Type & NiPSysBoxEmitter::GetType() const {
	return TYPE;
};

