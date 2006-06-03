/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkBlendController.h"

//Definition of TYPE constant
const Type bhkBlendController::TYPE("bhkBlendController", &BHK_BLEND_CONTROLLER_PARENT::TYPE );

bhkBlendController::bhkBlendController() BHK_BLEND_CONTROLLER_CONSTRUCT {}

bhkBlendController::~bhkBlendController() {}

void bhkBlendController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	BHK_BLEND_CONTROLLER_READ
}

void bhkBlendController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_BLEND_CONTROLLER_WRITE
}

string bhkBlendController::asString( bool verbose ) const {
	BHK_BLEND_CONTROLLER_STRING
}

void bhkBlendController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	BHK_BLEND_CONTROLLER_FIXLINKS
}

const Type & bhkBlendController::GetType() const {
	return TYPE;
};

