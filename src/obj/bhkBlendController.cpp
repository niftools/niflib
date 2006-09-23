/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkBlendController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBlendController::TYPE("bhkBlendController", &BHK_BLEND_CONTROLLER_PARENT::TypeConst() );

bhkBlendController::bhkBlendController() BHK_BLEND_CONTROLLER_CONSTRUCT {}

bhkBlendController::~bhkBlendController() {}

void bhkBlendController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkBlendController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkBlendController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkBlendController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkBlendController::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkBlendController::GetType() const {
	return TYPE;
};

