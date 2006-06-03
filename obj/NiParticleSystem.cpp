/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiParticleSystem.h"

//Definition of TYPE constant
const Type NiParticleSystem::TYPE("NiParticleSystem", &NI_PARTICLE_SYSTEM_PARENT::TYPE );

NiParticleSystem::NiParticleSystem() NI_PARTICLE_SYSTEM_CONSTRUCT {}

NiParticleSystem::~NiParticleSystem() {}

void NiParticleSystem::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_PARTICLE_SYSTEM_READ
}

void NiParticleSystem::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_PARTICLE_SYSTEM_WRITE
}

string NiParticleSystem::asString( bool verbose ) const {
  NI_PARTICLE_SYSTEM_STRING
}

void NiParticleSystem::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_PARTICLE_SYSTEM_FIXLINKS
}

const Type & NiParticleSystem::GetType() const {
  return TYPE;
};

