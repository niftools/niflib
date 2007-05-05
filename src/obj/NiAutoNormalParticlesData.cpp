/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAutoNormalParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAutoNormalParticlesData::TYPE("NiAutoNormalParticlesData", &NI_AUTO_NORMAL_PARTICLES_DATA_PARENT::TYPE );

NiAutoNormalParticlesData::NiAutoNormalParticlesData() NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT {}

NiAutoNormalParticlesData::~NiAutoNormalParticlesData() {}

void NiAutoNormalParticlesData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAutoNormalParticlesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAutoNormalParticlesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAutoNormalParticlesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAutoNormalParticlesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAutoNormalParticlesData::GetType() const {
	return TYPE;
};
