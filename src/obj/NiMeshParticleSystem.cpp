/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMeshParticleSystem.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshParticleSystem::TYPE("NiMeshParticleSystem", &NI_MESH_PARTICLE_SYSTEM_PARENT::TYPE );

NiMeshParticleSystem::NiMeshParticleSystem() NI_MESH_PARTICLE_SYSTEM_CONSTRUCT {}

NiMeshParticleSystem::~NiMeshParticleSystem() {}

void NiMeshParticleSystem::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiMeshParticleSystem::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiMeshParticleSystem::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMeshParticleSystem::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiMeshParticleSystem::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMeshParticleSystem::GetType() const {
	return TYPE;
};
