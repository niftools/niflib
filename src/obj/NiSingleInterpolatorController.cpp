/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSingleInterpolatorController.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSingleInterpolatorController::TYPE("NiSingleInterpolatorController", &NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT::TYPE );

NiSingleInterpolatorController::NiSingleInterpolatorController() NI_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT {}

NiSingleInterpolatorController::~NiSingleInterpolatorController() {}

void NiSingleInterpolatorController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSingleInterpolatorController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSingleInterpolatorController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSingleInterpolatorController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiSingleInterpolatorController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSingleInterpolatorController::GetType() const {
	return TYPE;
};

Ref<NiInterpolator > NiSingleInterpolatorController::GetInterpolator() const {
	return interpolator;
}

void NiSingleInterpolatorController::SetInterpolator( NiInterpolator * value ) {
	interpolator = value;
}
