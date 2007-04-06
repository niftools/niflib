/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleGrowFade.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleGrowFade::TYPE("NiParticleGrowFade", &NI_PARTICLE_GROW_FADE_PARENT::TypeConst() );

NiParticleGrowFade::NiParticleGrowFade() NI_PARTICLE_GROW_FADE_CONSTRUCT {}

NiParticleGrowFade::~NiParticleGrowFade() {}

void NiParticleGrowFade::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticleGrowFade::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticleGrowFade::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleGrowFade::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticleGrowFade::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleGrowFade::GetType() const {
	return TYPE;
};

const Type & NiParticleGrowFade::TypeConst() {
	return TYPE;
}
