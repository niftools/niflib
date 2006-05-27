/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "ASingleInterpolatorController.h"
#include "AInterpolator.h"

//Definition of TYPE constant
const Type ASingleInterpolatorController::TYPE("ASingleInterpolatorController", &A_SINGLE_INTERPOLATOR_CONTROLLER_PARENT::TYPE );

ASingleInterpolatorController::ASingleInterpolatorController() A_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT {}

ASingleInterpolatorController::~ASingleInterpolatorController() {}

void ASingleInterpolatorController::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	A_SINGLE_INTERPOLATOR_CONTROLLER_READ
}

void ASingleInterpolatorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_SINGLE_INTERPOLATOR_CONTROLLER_WRITE
}

string ASingleInterpolatorController::asString( bool verbose ) const {
	A_SINGLE_INTERPOLATOR_CONTROLLER_STRING
}

void ASingleInterpolatorController::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	A_SINGLE_INTERPOLATOR_CONTROLLER_FIXLINKS
}

