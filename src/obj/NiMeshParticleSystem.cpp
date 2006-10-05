/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMeshParticleSystem.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshParticleSystem::TYPE("NiMeshParticleSystem", &NI_MESH_PARTICLE_SYSTEM_PARENT::TypeConst() );

NiMeshParticleSystem::NiMeshParticleSystem() NI_MESH_PARTICLE_SYSTEM_CONSTRUCT {}

NiMeshParticleSystem::~NiMeshParticleSystem() {}

void NiMeshParticleSystem::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiMeshParticleSystem::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiMeshParticleSystem::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMeshParticleSystem::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiMeshParticleSystem::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMeshParticleSystem::GetType() const {
	return TYPE;
};

