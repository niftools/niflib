/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/FxRadioButton.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type FxRadioButton::TYPE("FxRadioButton", &FX_RADIO_BUTTON_PARENT::TypeConst() );

FxRadioButton::FxRadioButton() FX_RADIO_BUTTON_CONSTRUCT {}

FxRadioButton::~FxRadioButton() {}

void FxRadioButton::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void FxRadioButton::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string FxRadioButton::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void FxRadioButton::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> FxRadioButton::GetRefs() const {
	return InternalGetRefs();
}

const Type & FxRadioButton::GetType() const {
	return TYPE;
};

