/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticles.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticles::TYPE("NiParticles", &NI_PARTICLES_PARENT::TypeConst() );

NiParticles::NiParticles() NI_PARTICLES_CONSTRUCT {}

NiParticles::~NiParticles() {}

void NiParticles::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticles::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticles::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticles::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticles::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticles::GetType() const {
	return TYPE;
};

