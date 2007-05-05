/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleBomb.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleBomb::TYPE("NiParticleBomb", &NI_PARTICLE_BOMB_PARENT::TYPE );

NiParticleBomb::NiParticleBomb() NI_PARTICLE_BOMB_CONSTRUCT {}

NiParticleBomb::~NiParticleBomb() {}

void NiParticleBomb::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticleBomb::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticleBomb::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleBomb::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticleBomb::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleBomb::GetType() const {
	return TYPE;
};
