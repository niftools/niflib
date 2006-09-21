/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLookAtController.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLookAtController::TYPE("NiLookAtController", &NI_LOOK_AT_CONTROLLER_PARENT::TypeConst() );

NiLookAtController::NiLookAtController() NI_LOOK_AT_CONTROLLER_CONSTRUCT {}

NiLookAtController::~NiLookAtController() {}

void NiLookAtController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LOOK_AT_CONTROLLER_READ
}

void NiLookAtController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_LOOK_AT_CONTROLLER_WRITE
}

string NiLookAtController::asString( bool verbose ) const {
	NI_LOOK_AT_CONTROLLER_STRING
}

void NiLookAtController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LOOK_AT_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiLookAtController::GetRefs() const {
	NI_LOOK_AT_CONTROLLER_GETREFS
}

const Type & NiLookAtController::GetType() const {
	return TYPE;
};

