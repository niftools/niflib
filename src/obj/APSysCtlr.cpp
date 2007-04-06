/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/APSysCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type APSysCtlr::TYPE("APSysCtlr", &A_P_SYS_CTLR_PARENT::TypeConst() );

APSysCtlr::APSysCtlr() A_P_SYS_CTLR_CONSTRUCT {}

APSysCtlr::~APSysCtlr() {}

void APSysCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void APSysCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string APSysCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void APSysCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> APSysCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & APSysCtlr::GetType() const {
	return TYPE;
};

string APSysCtlr::GetModifierName() const {
	return modifierName;
}

void APSysCtlr::SetModifierName( string value ) {
	modifierName = value;
}

const Type & APSysCtlr::TypeConst() {
	return TYPE;
}
