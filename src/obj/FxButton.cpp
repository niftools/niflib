/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/FxButton.h"
using namespace Niflib;

//Definition of TYPE constant
const Type FxButton::TYPE("FxButton", &FX_BUTTON_PARENT::TypeConst() );

FxButton::FxButton() FX_BUTTON_CONSTRUCT {}

FxButton::~FxButton() {}

void FxButton::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FX_BUTTON_READ
}

void FxButton::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	FX_BUTTON_WRITE
}

string FxButton::asString( bool verbose ) const {
	FX_BUTTON_STRING
}

void FxButton::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FX_BUTTON_FIXLINKS
}

list<NiObjectRef> FxButton::GetRefs() const {
	FX_BUTTON_GETREFS
}

const Type & FxButton::GetType() const {
	return TYPE;
};

