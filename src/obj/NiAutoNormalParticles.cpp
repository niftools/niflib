/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAutoNormalParticles.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAutoNormalParticles::TYPE("NiAutoNormalParticles", &NI_AUTO_NORMAL_PARTICLES_PARENT::TypeConst() );

NiAutoNormalParticles::NiAutoNormalParticles() NI_AUTO_NORMAL_PARTICLES_CONSTRUCT {}

NiAutoNormalParticles::~NiAutoNormalParticles() {}

void NiAutoNormalParticles::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiAutoNormalParticles::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiAutoNormalParticles::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAutoNormalParticles::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiAutoNormalParticles::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAutoNormalParticles::GetType() const {
	return TYPE;
};

