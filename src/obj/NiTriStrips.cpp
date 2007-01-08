/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTriStrips.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriStrips::TYPE("NiTriStrips", &NI_TRI_STRIPS_PARENT::TypeConst() );

NiTriStrips::NiTriStrips() NI_TRI_STRIPS_CONSTRUCT {}

NiTriStrips::~NiTriStrips() {}

void NiTriStrips::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTriStrips::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTriStrips::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTriStrips::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTriStrips::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTriStrips::GetType() const {
	return TYPE;
};

