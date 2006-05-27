/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiLightColorController.h"
#include "NiPosData.h"
#include "NiPoint3Interpolator.h"

//Definition of TYPE constant
const Type NiLightColorController::TYPE("NiLightColorController", &NI_LIGHT_COLOR_CONTROLLER_PARENT::TYPE );

NiLightColorController::NiLightColorController() NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT {}

NiLightColorController::~NiLightColorController() {}

void NiLightColorController::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_LIGHT_COLOR_CONTROLLER_READ
}

void NiLightColorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_LIGHT_COLOR_CONTROLLER_WRITE
}

string NiLightColorController::asString( bool verbose ) const {
	NI_LIGHT_COLOR_CONTROLLER_STRING
}

void NiLightColorController::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_LIGHT_COLOR_CONTROLLER_FIXLINKS
}

