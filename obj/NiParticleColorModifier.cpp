/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiParticleColorModifier.h"
#include "NiColorData.h"

//Definition of TYPE constant
const Type NiParticleColorModifier::TYPE("NiParticleColorModifier", &NI_PARTICLE_COLOR_MODIFIER_PARENT::TYPE );

NiParticleColorModifier::NiParticleColorModifier() NI_PARTICLE_COLOR_MODIFIER_CONSTRUCT {}

NiParticleColorModifier::~NiParticleColorModifier() {}

void NiParticleColorModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_COLOR_MODIFIER_READ
}

void NiParticleColorModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLE_COLOR_MODIFIER_WRITE
}

string NiParticleColorModifier::asString( bool verbose ) const {
	NI_PARTICLE_COLOR_MODIFIER_STRING
}

void NiParticleColorModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_COLOR_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiParticleColorModifier::GetRefs() const {
	NI_PARTICLE_COLOR_MODIFIER_GETREFS
}

const Type & NiParticleColorModifier::GetType() const {
	return TYPE;
};

