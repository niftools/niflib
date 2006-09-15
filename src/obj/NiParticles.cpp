/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiParticles.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticles::TYPE("NiParticles", &NI_PARTICLES_PARENT::TypeConst() );

NiParticles::NiParticles() NI_PARTICLES_CONSTRUCT {}

NiParticles::~NiParticles() {}

void NiParticles::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLES_READ
}

void NiParticles::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLES_WRITE
}

string NiParticles::asString( bool verbose ) const {
	NI_PARTICLES_STRING
}

void NiParticles::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLES_FIXLINKS
}

list<NiObjectRef> NiParticles::GetRefs() const {
	NI_PARTICLES_GETREFS
}

const Type & NiParticles::GetType() const {
	return TYPE;
};

