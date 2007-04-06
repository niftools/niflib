/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/FxButton.h"
using namespace Niflib;

//Definition of TYPE constant
const Type FxButton::TYPE("FxButton", &FX_BUTTON_PARENT::TypeConst() );

FxButton::FxButton() FX_BUTTON_CONSTRUCT {}

FxButton::~FxButton() {}

void FxButton::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void FxButton::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string FxButton::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void FxButton::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> FxButton::GetRefs() const {
	return InternalGetRefs();
}

const Type & FxButton::GetType() const {
	return TYPE;
};

const Type & FxButton::TypeConst() {
	return TYPE;
}
