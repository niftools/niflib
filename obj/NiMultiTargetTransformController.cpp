/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiMultiTargetTransformController.h"
#include "obj/NiNode.h"

//Definition of TYPE constant
const Type NiMultiTargetTransformController::TYPE("NiMultiTargetTransformController", &NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT::TYPE );

NiMultiTargetTransformController::NiMultiTargetTransformController() NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiMultiTargetTransformController::~NiMultiTargetTransformController() {}

void NiMultiTargetTransformController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_READ
}

void NiMultiTargetTransformController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_WRITE
}

string NiMultiTargetTransformController::asString( bool verbose ) const {
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_STRING
}

void NiMultiTargetTransformController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiMultiTargetTransformController::GetRefs() const {
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_GETREFS
}

const Type & NiMultiTargetTransformController::GetType() const {
	return TYPE;
};

