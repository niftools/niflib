/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleSystem.h"
#include "../../include/obj/NiPSysModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleSystem::TYPE("NiParticleSystem", &NI_PARTICLE_SYSTEM_PARENT::TypeConst() );

NiParticleSystem::NiParticleSystem() NI_PARTICLE_SYSTEM_CONSTRUCT {}

NiParticleSystem::~NiParticleSystem() {}

void NiParticleSystem::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_SYSTEM_READ
}

void NiParticleSystem::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLE_SYSTEM_WRITE
}

string NiParticleSystem::asString( bool verbose ) const {
	NI_PARTICLE_SYSTEM_STRING
}

void NiParticleSystem::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_SYSTEM_FIXLINKS
}

list<NiObjectRef> NiParticleSystem::GetRefs() const {
	NI_PARTICLE_SYSTEM_GETREFS
}

const Type & NiParticleSystem::GetType() const {
	return TYPE;
};

