/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiShadeProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiShadeProperty::TYPE("NiShadeProperty", &NI_SHADE_PROPERTY_PARENT::TypeConst() );

NiShadeProperty::NiShadeProperty() NI_SHADE_PROPERTY_CONSTRUCT {}

NiShadeProperty::~NiShadeProperty() {}

void NiShadeProperty::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiShadeProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiShadeProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiShadeProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiShadeProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiShadeProperty::GetType() const {
	return TYPE;
};

unsigned short NiShadeProperty::GetFlags() const {
   return flags;
}

void NiShadeProperty::SetFlags( unsigned short n ) {
   flags = n;
}

const Type & NiShadeProperty::TypeConst() {
	return TYPE;
}
