/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleMeshes.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleMeshes::TYPE("NiParticleMeshes", &NI_PARTICLE_MESHES_PARENT::TypeConst() );

NiParticleMeshes::NiParticleMeshes() NI_PARTICLE_MESHES_CONSTRUCT {}

NiParticleMeshes::~NiParticleMeshes() {}

void NiParticleMeshes::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleMeshes::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleMeshes::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleMeshes::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleMeshes::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleMeshes::GetType() const {
	return TYPE;
};

