/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticles.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticles::TYPE("NiParticles", &NI_PARTICLES_PARENT::TYPE );

NiParticles::NiParticles() NI_PARTICLES_CONSTRUCT {}

NiParticles::~NiParticles() {}

void NiParticles::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticles::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticles::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticles::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticles::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticles::GetType() const {
	return TYPE;
};
