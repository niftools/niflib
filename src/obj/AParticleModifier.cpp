/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AParticleModifier.h"
#include "../../include/obj/NiParticleSystemController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AParticleModifier::TYPE("AParticleModifier", &A_PARTICLE_MODIFIER_PARENT::TypeConst() );

AParticleModifier::AParticleModifier() A_PARTICLE_MODIFIER_CONSTRUCT {}

AParticleModifier::~AParticleModifier() {}

void AParticleModifier::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void AParticleModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string AParticleModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AParticleModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> AParticleModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & AParticleModifier::GetType() const {
	return TYPE;
};

