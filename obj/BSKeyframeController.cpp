/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "BSKeyframeController.h"
#include "NiKeyframeData.h"

//Definition of TYPE constant
const Type BSKeyframeController::TYPE("BSKeyframeController", &B_S_KEYFRAME_CONTROLLER_PARENT::TYPE );

BSKeyframeController::BSKeyframeController() B_S_KEYFRAME_CONTROLLER_CONSTRUCT {}

BSKeyframeController::~BSKeyframeController() {}

void BSKeyframeController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	B_S_KEYFRAME_CONTROLLER_READ
}

void BSKeyframeController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	B_S_KEYFRAME_CONTROLLER_WRITE
}

string BSKeyframeController::asString( bool verbose ) const {
	B_S_KEYFRAME_CONTROLLER_STRING
}

void BSKeyframeController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	B_S_KEYFRAME_CONTROLLER_FIXLINKS
}

