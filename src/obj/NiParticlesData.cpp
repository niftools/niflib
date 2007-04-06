/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NI_PARTICLES_DATA_PARENT::TypeConst() );

NiParticlesData::NiParticlesData() NI_PARTICLES_DATA_CONSTRUCT {}

NiParticlesData::~NiParticlesData() {}

void NiParticlesData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticlesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticlesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticlesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticlesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticlesData::GetType() const {
	return TYPE;
};

const Type & NiParticlesData::TypeConst() {
	return TYPE;
}
