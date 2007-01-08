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

void NiParticleSystemController::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleSystemController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleSystemController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleSystemController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleSystemController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleSystemController::GetType() const {
	return TYPE;
};

