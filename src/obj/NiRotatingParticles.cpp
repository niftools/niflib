/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiRotatingParticles.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRotatingParticles::TYPE("NiRotatingParticles", &NI_ROTATING_PARTICLES_PARENT::TypeConst() );

NiRotatingParticles::NiRotatingParticles() NI_ROTATING_PARTICLES_CONSTRUCT {}

NiRotatingParticles::~NiRotatingParticles() {}

void NiRotatingParticles::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiRotatingParticles::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiRotatingParticles::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiRotatingParticles::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiRotatingParticles::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiRotatingParticles::GetType() const {
	return TYPE;
};

