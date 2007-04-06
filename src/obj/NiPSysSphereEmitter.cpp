/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysSphereEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysSphereEmitter::TYPE("NiPSysSphereEmitter", &NI_P_SYS_SPHERE_EMITTER_PARENT::TypeConst() );

NiPSysSphereEmitter::NiPSysSphereEmitter() NI_P_SYS_SPHERE_EMITTER_CONSTRUCT {}

NiPSysSphereEmitter::~NiPSysSphereEmitter() {}

void NiPSysSphereEmitter::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysSphereEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysSphereEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysSphereEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysSphereEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysSphereEmitter::GetType() const {
	return TYPE;
};

const Type & NiPSysSphereEmitter::TypeConst() {
	return TYPE;
}
