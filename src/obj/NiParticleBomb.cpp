/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleBomb.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleBomb::TYPE("NiParticleBomb", &NI_PARTICLE_BOMB_PARENT::TypeConst() );

NiParticleBomb::NiParticleBomb() NI_PARTICLE_BOMB_CONSTRUCT {}

NiParticleBomb::~NiParticleBomb() {}

void NiParticleBomb::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleBomb::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleBomb::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleBomb::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleBomb::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleBomb::GetType() const {
	return TYPE;
};

const Type & NiParticleBomb::TypeConst() {
	return TYPE;
}
