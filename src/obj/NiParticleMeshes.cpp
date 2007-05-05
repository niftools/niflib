/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleMeshes.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleMeshes::TYPE("NiParticleMeshes", &NI_PARTICLE_MESHES_PARENT::TYPE );

NiParticleMeshes::NiParticleMeshes() NI_PARTICLE_MESHES_CONSTRUCT {}

NiParticleMeshes::~NiParticleMeshes() {}

void NiParticleMeshes::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticleMeshes::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticleMeshes::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleMeshes::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticleMeshes::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleMeshes::GetType() const {
	return TYPE;
};
