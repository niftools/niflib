/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiSingleInterpolatorController.h"
#include "obj/NiInterpolator.h"

//Definition of TYPE constant
const Type NiSingleInterpolatorController::TYPE("NiSingleInterpolatorController", &NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT::TYPE );

NiSingleInterpolatorController::NiSingleInterpolatorController() NI_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT {}

NiSingleInterpolatorController::~NiSingleInterpolatorController() {}

void NiSingleInterpolatorController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SINGLE_INTERPOLATOR_CONTROLLER_READ
}

void NiSingleInterpolatorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SINGLE_INTERPOLATOR_CONTROLLER_WRITE
}

string NiSingleInterpolatorController::asString( bool verbose ) const {
	NI_SINGLE_INTERPOLATOR_CONTROLLER_STRING
}

void NiSingleInterpolatorController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SINGLE_INTERPOLATOR_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiSingleInterpolatorController::GetRefs() const {
	NI_SINGLE_INTERPOLATOR_CONTROLLER_GETREFS
}

const Type & NiSingleInterpolatorController::GetType() const {
	return TYPE;
};

