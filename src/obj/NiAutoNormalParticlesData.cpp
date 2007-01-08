/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAutoNormalParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAutoNormalParticlesData::TYPE("NiAutoNormalParticlesData", &NI_AUTO_NORMAL_PARTICLES_DATA_PARENT::TypeConst() );

NiAutoNormalParticlesData::NiAutoNormalParticlesData() NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT {}

NiAutoNormalParticlesData::~NiAutoNormalParticlesData() {}

void NiAutoNormalParticlesData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiAutoNormalParticlesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiAutoNormalParticlesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAutoNormalParticlesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiAutoNormalParticlesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAutoNormalParticlesData::GetType() const {
	return TYPE;
};

