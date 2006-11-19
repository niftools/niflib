/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysSphereEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysSphereEmitter::TYPE("NiPSysSphereEmitter", &NI_P_SYS_SPHERE_EMITTER_PARENT::TypeConst() );

NiPSysSphereEmitter::NiPSysSphereEmitter() NI_P_SYS_SPHERE_EMITTER_CONSTRUCT {}

NiPSysSphereEmitter::~NiPSysSphereEmitter() {}

void NiPSysSphereEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysSphereEmitter::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysSphereEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysSphereEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysSphereEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysSphereEmitter::GetType() const {
	return TYPE;
};

