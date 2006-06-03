/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiKeyframeController.h"

//Definition of TYPE constant
const Type NiKeyframeController::TYPE("NiKeyframeController", &NI_KEYFRAME_CONTROLLER_PARENT::TYPE );

NiKeyframeController::NiKeyframeController() NI_KEYFRAME_CONTROLLER_CONSTRUCT {}

NiKeyframeController::~NiKeyframeController() {}

void NiKeyframeController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_KEYFRAME_CONTROLLER_READ
}

void NiKeyframeController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_KEYFRAME_CONTROLLER_WRITE
}

string NiKeyframeController::asString( bool verbose ) const {
	NI_KEYFRAME_CONTROLLER_STRING
}

void NiKeyframeController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_KEYFRAME_CONTROLLER_FIXLINKS
}

const Type & NiKeyframeController::GetType() const {
	return TYPE;
};

