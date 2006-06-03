/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiParticleGrowFade.h"

//Definition of TYPE constant
const Type NiParticleGrowFade::TYPE("NiParticleGrowFade", &NI_PARTICLE_GROW_FADE_PARENT::TYPE );

NiParticleGrowFade::NiParticleGrowFade() NI_PARTICLE_GROW_FADE_CONSTRUCT {}

NiParticleGrowFade::~NiParticleGrowFade() {}

void NiParticleGrowFade::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_PARTICLE_GROW_FADE_READ
}

void NiParticleGrowFade::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_PARTICLE_GROW_FADE_WRITE
}

string NiParticleGrowFade::asString( bool verbose ) const {
  NI_PARTICLE_GROW_FADE_STRING
}

void NiParticleGrowFade::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_PARTICLE_GROW_FADE_FIXLINKS
}

const Type & NiParticleGrowFade::GetType() const {
  return TYPE;
};

