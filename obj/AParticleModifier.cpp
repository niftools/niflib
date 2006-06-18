/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "AParticleModifier.h"
#include "NiParticleSystemController.h"
using namespace NifLib;

//Definition of TYPE constant
const Type AParticleModifier::TYPE("AParticleModifier", &A_PARTICLE_MODIFIER_PARENT::TypeConst() );

AParticleModifier::AParticleModifier() A_PARTICLE_MODIFIER_CONSTRUCT {}

AParticleModifier::~AParticleModifier() {}

void AParticleModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	A_PARTICLE_MODIFIER_READ
}

void AParticleModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	A_PARTICLE_MODIFIER_WRITE
}

string AParticleModifier::asString( bool verbose ) const {
	A_PARTICLE_MODIFIER_STRING
}

void AParticleModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	A_PARTICLE_MODIFIER_FIXLINKS
}

list<NiObjectRef> AParticleModifier::GetRefs() const {
	A_PARTICLE_MODIFIER_GETREFS
}

const Type & AParticleModifier::GetType() const {
	return TYPE;
};

