/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiRotatingParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRotatingParticlesData::TYPE("NiRotatingParticlesData", &NI_ROTATING_PARTICLES_DATA_PARENT::TypeConst() );

NiRotatingParticlesData::NiRotatingParticlesData() NI_ROTATING_PARTICLES_DATA_CONSTRUCT {}

NiRotatingParticlesData::~NiRotatingParticlesData() {}

void NiRotatingParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiRotatingParticlesData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiRotatingParticlesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiRotatingParticlesData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiRotatingParticlesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiRotatingParticlesData::GetType() const {
	return TYPE;
};

