/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleGrowFade.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleGrowFade::TYPE("NiParticleGrowFade", &NI_PARTICLE_GROW_FADE_PARENT::TypeConst() );

NiParticleGrowFade::NiParticleGrowFade() NI_PARTICLE_GROW_FADE_CONSTRUCT {}

NiParticleGrowFade::~NiParticleGrowFade() {}

void NiParticleGrowFade::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_GROW_FADE_READ
}

void NiParticleGrowFade::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLE_GROW_FADE_WRITE
}

string NiParticleGrowFade::asString( bool verbose ) const {
	NI_PARTICLE_GROW_FADE_STRING
}

void NiParticleGrowFade::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_GROW_FADE_FIXLINKS
}

list<NiObjectRef> NiParticleGrowFade::GetRefs() const {
	NI_PARTICLE_GROW_FADE_GETREFS
}

const Type & NiParticleGrowFade::GetType() const {
	return TYPE;
};

