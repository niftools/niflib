/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/FxButton.h"

//Definition of TYPE constant
const Type FxButton::TYPE("FxButton", &FX_BUTTON_PARENT::TYPE );

FxButton::FxButton() FX_BUTTON_CONSTRUCT {}

FxButton::~FxButton() {}

void FxButton::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  FX_BUTTON_READ
}

void FxButton::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  FX_BUTTON_WRITE
}

string FxButton::asString( bool verbose ) const {
  FX_BUTTON_STRING
}

void FxButton::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  FX_BUTTON_FIXLINKS
}

const Type & FxButton::GetType() const {
  return TYPE;
};

