/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSingleInterpolatorController.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSingleInterpolatorController::TYPE("NiSingleInterpolatorController", &NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT::TypeConst() );

NiSingleInterpolatorController::NiSingleInterpolatorController() NI_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT {}

NiSingleInterpolatorController::~NiSingleInterpolatorController() {}

void NiSingleInterpolatorController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiSingleInterpolatorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiSingleInterpolatorController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSingleInterpolatorController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

void NiSingleInterpolatorController::SetInterpolator( Ref<NiInterpolator > value ) {
	interpolator = value;
}

