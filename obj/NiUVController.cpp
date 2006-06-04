/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiUVController.h"
#include "obj/NiUVData.h"

//Definition of TYPE constant
const Type NiUVController::TYPE("NiUVController", &NI_U_V_CONTROLLER_PARENT::TYPE );

NiUVController::NiUVController() NI_U_V_CONTROLLER_CONSTRUCT {}

NiUVController::~NiUVController() {}

void NiUVController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_U_V_CONTROLLER_READ
}

void NiUVController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_U_V_CONTROLLER_WRITE
}

string NiUVController::asString( bool verbose ) const {
	NI_U_V_CONTROLLER_STRING
}

void NiUVController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_U_V_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiUVController::GetRefs() const {
	NI_U_V_CONTROLLER_GETREFS
}

const Type & NiUVController::GetType() const {
	return TYPE;
};

