/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiMeshParticleSystem.h"

//Definition of TYPE constant
const Type NiMeshParticleSystem::TYPE("NiMeshParticleSystem", &NI_MESH_PARTICLE_SYSTEM_PARENT::TypeConst() );

NiMeshParticleSystem::NiMeshParticleSystem() NI_MESH_PARTICLE_SYSTEM_CONSTRUCT {}

NiMeshParticleSystem::~NiMeshParticleSystem() {}

void NiMeshParticleSystem::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MESH_PARTICLE_SYSTEM_READ
}

void NiMeshParticleSystem::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_MESH_PARTICLE_SYSTEM_WRITE
}

string NiMeshParticleSystem::asString( bool verbose ) const {
	NI_MESH_PARTICLE_SYSTEM_STRING
}

void NiMeshParticleSystem::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MESH_PARTICLE_SYSTEM_FIXLINKS
}

list<NiObjectRef> NiMeshParticleSystem::GetRefs() const {
	NI_MESH_PARTICLE_SYSTEM_GETREFS
}

const Type & NiMeshParticleSystem::GetType() const {
	return TYPE;
};

