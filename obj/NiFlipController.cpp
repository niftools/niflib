/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFlipController.h"
#include "NiSourceTexture.h"

//Definition of TYPE constant
const Type NiFlipController::TYPE("NiFlipController", &NI_FLIP_CONTROLLER_PARENT::TYPE );

NiFlipController::NiFlipController() NI_FLIP_CONTROLLER_CONSTRUCT {}

NiFlipController::~NiFlipController() {}

void NiFlipController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_FLIP_CONTROLLER_READ
}

void NiFlipController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_FLIP_CONTROLLER_WRITE
}

string NiFlipController::asString( bool verbose ) const {
  NI_FLIP_CONTROLLER_STRING
}

void NiFlipController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_FLIP_CONTROLLER_FIXLINKS
}

const Type & NiFlipController::GetType() const {
  return TYPE;
};

