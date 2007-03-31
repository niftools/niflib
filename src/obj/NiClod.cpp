/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiClod.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiClod::TYPE("NiClod", &NI_CLOD_PARENT::TypeConst() );

NiClod::NiClod() NI_CLOD_CONSTRUCT {}

NiClod::~NiClod() {}

void NiClod::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiClod::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiClod::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiClod::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiClod::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiClod::GetType() const {
	return TYPE;
};

const Type & NiClod::TypeConst() {
	return TYPE;
}
