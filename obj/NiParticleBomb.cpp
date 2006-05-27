/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiParticleBomb.h"

//Definition of TYPE constant
const Type NiParticleBomb::TYPE("NiParticleBomb", &NI_PARTICLE_BOMB_PARENT::TYPE );

NiParticleBomb::NiParticleBomb() NI_PARTICLE_BOMB_CONSTRUCT {}

NiParticleBomb::~NiParticleBomb() {}

void NiParticleBomb::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_PARTICLE_BOMB_READ
}

void NiParticleBomb::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PARTICLE_BOMB_WRITE
}

string NiParticleBomb::asString( bool verbose ) const {
	NI_PARTICLE_BOMB_STRING
}

void NiParticleBomb::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_PARTICLE_BOMB_FIXLINKS
}

