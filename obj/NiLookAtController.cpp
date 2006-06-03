/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiLookAtController.h"

//Definition of TYPE constant
const Type NiLookAtController::TYPE("NiLookAtController", &NI_LOOK_AT_CONTROLLER_PARENT::TYPE );

NiLookAtController::NiLookAtController() NI_LOOK_AT_CONTROLLER_CONSTRUCT {}

NiLookAtController::~NiLookAtController() {}

void NiLookAtController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_LOOK_AT_CONTROLLER_READ
}

void NiLookAtController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_LOOK_AT_CONTROLLER_WRITE
}

string NiLookAtController::asString( bool verbose ) const {
  NI_LOOK_AT_CONTROLLER_STRING
}

void NiLookAtController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_LOOK_AT_CONTROLLER_FIXLINKS
}

const Type & NiLookAtController::GetType() const {
  return TYPE;
};

