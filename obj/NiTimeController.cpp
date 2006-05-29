/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTimeController.h"

//Definition of TYPE constant
const Type NiTimeController::TYPE("NiTimeController", &NI_TIME_CONTROLLER_PARENT::TYPE );

NiTimeController::NiTimeController() NI_TIME_CONTROLLER_CONSTRUCT {}

NiTimeController::~NiTimeController() {}

void NiTimeController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_TIME_CONTROLLER_READ
}

void NiTimeController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TIME_CONTROLLER_WRITE
}

string NiTimeController::asString( bool verbose ) const {
	NI_TIME_CONTROLLER_STRING
}

void NiTimeController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_TIME_CONTROLLER_FIXLINKS
}

