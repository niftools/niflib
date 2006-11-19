/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/APSysCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type APSysCtlr::TYPE("APSysCtlr", &A_P_SYS_CTLR_PARENT::TypeConst() );

APSysCtlr::APSysCtlr() A_P_SYS_CTLR_CONSTRUCT {}

APSysCtlr::~APSysCtlr() {}

void APSysCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void APSysCtlr::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string APSysCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void APSysCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

