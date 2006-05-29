/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "FxRadioButton.h"

//Definition of TYPE constant
const Type FxRadioButton::TYPE("FxRadioButton", &FX_RADIO_BUTTON_PARENT::TYPE );

FxRadioButton::FxRadioButton() FX_RADIO_BUTTON_CONSTRUCT {}

FxRadioButton::~FxRadioButton() {}

void FxRadioButton::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	FX_RADIO_BUTTON_READ
}

void FxRadioButton::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	FX_RADIO_BUTTON_WRITE
}

string FxRadioButton::asString( bool verbose ) const {
	FX_RADIO_BUTTON_STRING
}

void FxRadioButton::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	FX_RADIO_BUTTON_FIXLINKS
}

