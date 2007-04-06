/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleSystem.h"
#include "../../include/obj/NiPSysModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleSystem::TYPE("NiParticleSystem", &NI_PARTICLE_SYSTEM_PARENT::TypeConst() );

NiParticleSystem::NiParticleSystem() NI_PARTICLE_SYSTEM_CONSTRUCT {}

NiParticleSystem::~NiParticleSystem() {}

void NiParticleSystem::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticleSystem::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticleSystem::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleSystem::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticleSystem::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleSystem::GetType() const {
	return TYPE;
};

const Type & NiParticleSystem::TypeConst() {
	return TYPE;
}
