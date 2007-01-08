/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLookAtController.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLookAtController::TYPE("NiLookAtController", &NI_LOOK_AT_CONTROLLER_PARENT::TypeConst() );

NiLookAtController::NiLookAtController() NI_LOOK_AT_CONTROLLER_CONSTRUCT {}

NiLookAtController::~NiLookAtController() {}

void NiLookAtController::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiLookAtController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiLookAtController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLookAtController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiLookAtController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLookAtController::GetType() const {
	return TYPE;
};

