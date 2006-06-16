/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysSphereEmitter.h"

//Definition of TYPE constant
const Type NiPSysSphereEmitter::TYPE("NiPSysSphereEmitter", &NI_P_SYS_SPHERE_EMITTER_PARENT::TypeConst() );

NiPSysSphereEmitter::NiPSysSphereEmitter() NI_P_SYS_SPHERE_EMITTER_CONSTRUCT {}

NiPSysSphereEmitter::~NiPSysSphereEmitter() {}

void NiPSysSphereEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_SPHERE_EMITTER_READ
}

void NiPSysSphereEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_SPHERE_EMITTER_WRITE
}

string NiPSysSphereEmitter::asString( bool verbose ) const {
	NI_P_SYS_SPHERE_EMITTER_STRING
}

void NiPSysSphereEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_SPHERE_EMITTER_FIXLINKS
}

list<NiObjectRef> NiPSysSphereEmitter::GetRefs() const {
	NI_P_SYS_SPHERE_EMITTER_GETREFS
}

const Type & NiPSysSphereEmitter::GetType() const {
	return TYPE;
};

