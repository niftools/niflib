/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFloatExtraDataController.h"

//Definition of TYPE constant
const Type NiFloatExtraDataController::TYPE("NiFloatExtraDataController", &NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENT::TYPE );

NiFloatExtraDataController::NiFloatExtraDataController() NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT {}

NiFloatExtraDataController::~NiFloatExtraDataController() {}

void NiFloatExtraDataController::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_FLOAT_EXTRA_DATA_CONTROLLER_READ
}

void NiFloatExtraDataController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_FLOAT_EXTRA_DATA_CONTROLLER_WRITE
}

string NiFloatExtraDataController::asString( bool verbose ) const {
	NI_FLOAT_EXTRA_DATA_CONTROLLER_STRING
}

void NiFloatExtraDataController::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_FLOAT_EXTRA_DATA_CONTROLLER_FIXLINKS
}

