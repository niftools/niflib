/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleSystemController.h"
#include "../../include/gen/Particle.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/AParticleModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleSystemController::TYPE("NiParticleSystemController", &NI_PARTICLE_SYSTEM_CONTROLLER_PARENT::TypeConst() );

NiParticleSystemController::NiParticleSystemController() NI_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT {}

NiParticleSystemController::~NiParticleSystemController() {}

void NiParticleSystemController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticleSystemController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticleSystemController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleSystemController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticleSystemController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleSystemController::GetType() const {
	return TYPE;
};

const Type & NiParticleSystemController::TypeConst() {
	return TYPE;
}
