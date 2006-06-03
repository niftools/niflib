/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBSPArrayController.h"

//Definition of TYPE constant
const Type NiBSPArrayController::TYPE("NiBSPArrayController", &NI_B_S_P_ARRAY_CONTROLLER_PARENT::TYPE );

NiBSPArrayController::NiBSPArrayController() NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT {}

NiBSPArrayController::~NiBSPArrayController() {}

void NiBSPArrayController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_B_S_P_ARRAY_CONTROLLER_READ
}

void NiBSPArrayController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_B_S_P_ARRAY_CONTROLLER_WRITE
}

string NiBSPArrayController::asString( bool verbose ) const {
  NI_B_S_P_ARRAY_CONTROLLER_STRING
}

void NiBSPArrayController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_B_S_P_ARRAY_CONTROLLER_FIXLINKS
}

const Type & NiBSPArrayController::GetType() const {
  return TYPE;
};

