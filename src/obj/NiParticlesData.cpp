/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NI_PARTICLES_DATA_PARENT::TypeConst() );

NiParticlesData::NiParticlesData() NI_PARTICLES_DATA_CONSTRUCT {}

NiParticlesData::~NiParticlesData() {}

void NiParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticlesData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticlesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticlesData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticlesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticlesData::GetType() const {
	return TYPE;
};

