/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiParticleSystemController.h"
#include "AParticleModifier.h"

//Definition of TYPE constant
const Type NiParticleSystemController::TYPE("NiParticleSystemController", &NI_PARTICLE_SYSTEM_CONTROLLER_PARENT::TYPE );

NiParticleSystemController::NiParticleSystemController() NI_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT {}

NiParticleSystemController::~NiParticleSystemController() {}

void NiParticleSystemController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_PARTICLE_SYSTEM_CONTROLLER_READ
}

void NiParticleSystemController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PARTICLE_SYSTEM_CONTROLLER_WRITE
}

string NiParticleSystemController::asString( bool verbose ) const {
	NI_PARTICLE_SYSTEM_CONTROLLER_STRING
}

void NiParticleSystemController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_PARTICLE_SYSTEM_CONTROLLER_FIXLINKS
}

