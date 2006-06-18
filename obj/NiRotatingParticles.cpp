/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiRotatingParticles.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiRotatingParticles::TYPE("NiRotatingParticles", &NI_ROTATING_PARTICLES_PARENT::TypeConst() );

NiRotatingParticles::NiRotatingParticles() NI_ROTATING_PARTICLES_CONSTRUCT {}

NiRotatingParticles::~NiRotatingParticles() {}

void NiRotatingParticles::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ROTATING_PARTICLES_READ
}

void NiRotatingParticles::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_ROTATING_PARTICLES_WRITE
}

string NiRotatingParticles::asString( bool verbose ) const {
	NI_ROTATING_PARTICLES_STRING
}

void NiRotatingParticles::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ROTATING_PARTICLES_FIXLINKS
}

list<NiObjectRef> NiRotatingParticles::GetRefs() const {
	NI_ROTATING_PARTICLES_GETREFS
}

const Type & NiRotatingParticles::GetType() const {
	return TYPE;
};

