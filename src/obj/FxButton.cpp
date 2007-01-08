/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/FxButton.h"
using namespace Niflib;

//Definition of TYPE constant
const Type FxButton::TYPE("FxButton", &FX_BUTTON_PARENT::TypeConst() );

FxButton::FxButton() FX_BUTTON_CONSTRUCT {}

FxButton::~FxButton() {}

void FxButton::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void FxButton::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string FxButton::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void FxButton::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> FxButton::GetRefs() const {
	return InternalGetRefs();
}

const Type & FxButton::GetType() const {
	return TYPE;
};

