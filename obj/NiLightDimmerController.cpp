/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiLightDimmerController.h"
#include "NiInterpolator.h"

//Definition of TYPE constant
const Type NiLightDimmerController::TYPE("NiLightDimmerController", &NI_LIGHT_DIMMER_CONTROLLER_PARENT::TypeConst() );

NiLightDimmerController::NiLightDimmerController() NI_LIGHT_DIMMER_CONTROLLER_CONSTRUCT {}

NiLightDimmerController::~NiLightDimmerController() {}

void NiLightDimmerController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LIGHT_DIMMER_CONTROLLER_READ
}

void NiLightDimmerController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_LIGHT_DIMMER_CONTROLLER_WRITE
}

string NiLightDimmerController::asString( bool verbose ) const {
	NI_LIGHT_DIMMER_CONTROLLER_STRING
}

void NiLightDimmerController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LIGHT_DIMMER_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiLightDimmerController::GetRefs() const {
	NI_LIGHT_DIMMER_CONTROLLER_GETREFS
}

const Type & NiLightDimmerController::GetType() const {
	return TYPE;
};

