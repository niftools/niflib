/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkBlendController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBlendController::TYPE("bhkBlendController", &BHK_BLEND_CONTROLLER_PARENT::TYPE );

bhkBlendController::bhkBlendController() BHK_BLEND_CONTROLLER_CONSTRUCT {}

bhkBlendController::~bhkBlendController() {}

void bhkBlendController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkBlendController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkBlendController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkBlendController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkBlendController::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkBlendController::GetType() const {
	return TYPE;
};
