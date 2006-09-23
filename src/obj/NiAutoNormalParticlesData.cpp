/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAutoNormalParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAutoNormalParticlesData::TYPE("NiAutoNormalParticlesData", &NI_AUTO_NORMAL_PARTICLES_DATA_PARENT::TypeConst() );

NiAutoNormalParticlesData::NiAutoNormalParticlesData() NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT {}

NiAutoNormalParticlesData::~NiAutoNormalParticlesData() {}

void NiAutoNormalParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiAutoNormalParticlesData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiAutoNormalParticlesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAutoNormalParticlesData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiAutoNormalParticlesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAutoNormalParticlesData::GetType() const {
	return TYPE;
};

