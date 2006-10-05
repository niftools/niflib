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
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleSystem::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleSystem::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleSystem::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleSystem::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleSystem::GetType() const {
	return TYPE;
};

