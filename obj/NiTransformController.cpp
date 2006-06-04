/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiTransformController.h"

//Definition of TYPE constant
const Type NiTransformController::TYPE("NiTransformController", &NI_TRANSFORM_CONTROLLER_PARENT::TYPE );

NiTransformController::NiTransformController() NI_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTransformController::~NiTransformController() {}

void NiTransformController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_TRANSFORM_CONTROLLER_READ
}

void NiTransformController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TRANSFORM_CONTROLLER_WRITE
}

string NiTransformController::asString( bool verbose ) const {
	NI_TRANSFORM_CONTROLLER_STRING
}

void NiTransformController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_TRANSFORM_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiTransformController::GetRefs() const {
	NI_TRANSFORM_CONTROLLER_GETREFS
}

const Type & NiTransformController::GetType() const {
	return TYPE;
};

