/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSpecularProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSpecularProperty::TYPE("NiSpecularProperty", &NI_SPECULAR_PROPERTY_PARENT::TypeConst() );

NiSpecularProperty::NiSpecularProperty() NI_SPECULAR_PROPERTY_CONSTRUCT {}

NiSpecularProperty::~NiSpecularProperty() {}

void NiSpecularProperty::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiSpecularProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiSpecularProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSpecularProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiSpecularProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSpecularProperty::GetType() const {
	return TYPE;
};

unsigned short NiSpecularProperty::GetFlags() const {
   return flags;
}

void NiSpecularProperty::SetFlags( unsigned short n ) {
   flags = n;
}

const Type & NiSpecularProperty::TypeConst() {
	return TYPE;
}
