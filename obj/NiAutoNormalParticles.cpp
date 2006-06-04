/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiAutoNormalParticles.h"

//Definition of TYPE constant
const Type NiAutoNormalParticles::TYPE("NiAutoNormalParticles", &NI_AUTO_NORMAL_PARTICLES_PARENT::TYPE );

NiAutoNormalParticles::NiAutoNormalParticles() NI_AUTO_NORMAL_PARTICLES_CONSTRUCT {}

NiAutoNormalParticles::~NiAutoNormalParticles() {}

void NiAutoNormalParticles::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_AUTO_NORMAL_PARTICLES_READ
}

void NiAutoNormalParticles::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_AUTO_NORMAL_PARTICLES_WRITE
}

string NiAutoNormalParticles::asString( bool verbose ) const {
	NI_AUTO_NORMAL_PARTICLES_STRING
}

void NiAutoNormalParticles::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_AUTO_NORMAL_PARTICLES_FIXLINKS
}

list<NiObjectRef> NiAutoNormalParticles::GetRefs() const {
	NI_AUTO_NORMAL_PARTICLES_GETREFS
}

const Type & NiAutoNormalParticles::GetType() const {
	return TYPE;
};

