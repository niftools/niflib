/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLookAtController.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLookAtController::TYPE("NiLookAtController", &NI_LOOK_AT_CONTROLLER_PARENT::TypeConst() );

NiLookAtController::NiLookAtController() NI_LOOK_AT_CONTROLLER_CONSTRUCT {}

NiLookAtController::~NiLookAtController() {}

void NiLookAtController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiLookAtController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiLookAtController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLookAtController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiLookAtController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLookAtController::GetType() const {
	return TYPE;
};

const Type & NiLookAtController::TypeConst() {
	return TYPE;
}
