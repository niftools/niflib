/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiRotatingParticles.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRotatingParticles::TYPE("NiRotatingParticles", &NI_ROTATING_PARTICLES_PARENT::TYPE );

NiRotatingParticles::NiRotatingParticles() NI_ROTATING_PARTICLES_CONSTRUCT {}

NiRotatingParticles::~NiRotatingParticles() {}

void NiRotatingParticles::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiRotatingParticles::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiRotatingParticles::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiRotatingParticles::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiRotatingParticles::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiRotatingParticles::GetType() const {
	return TYPE;
};
