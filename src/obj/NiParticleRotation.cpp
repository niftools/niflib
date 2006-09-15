/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleRotation.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleRotation::TYPE("NiParticleRotation", &NI_PARTICLE_ROTATION_PARENT::TypeConst() );

NiParticleRotation::NiParticleRotation() NI_PARTICLE_ROTATION_CONSTRUCT {}

NiParticleRotation::~NiParticleRotation() {}

void NiParticleRotation::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_ROTATION_READ
}

void NiParticleRotation::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLE_ROTATION_WRITE
}

string NiParticleRotation::asString( bool verbose ) const {
	NI_PARTICLE_ROTATION_STRING
}

void NiParticleRotation::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_ROTATION_FIXLINKS
}

list<NiObjectRef> NiParticleRotation::GetRefs() const {
	NI_PARTICLE_ROTATION_GETREFS
}

const Type & NiParticleRotation::GetType() const {
	return TYPE;
};

