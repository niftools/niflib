/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleRotation.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleRotation::TYPE("NiParticleRotation", &NI_PARTICLE_ROTATION_PARENT::TypeConst() );

NiParticleRotation::NiParticleRotation() NI_PARTICLE_ROTATION_CONSTRUCT {}

NiParticleRotation::~NiParticleRotation() {}

void NiParticleRotation::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleRotation::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleRotation::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleRotation::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleRotation::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleRotation::GetType() const {
	return TYPE;
};

const Type & NiParticleRotation::TypeConst() {
	return TYPE;
}
