/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSpecularProperty.h"

//Definition of TYPE constant
const Type NiSpecularProperty::TYPE("NiSpecularProperty", &NI_SPECULAR_PROPERTY_PARENT::TYPE );

NiSpecularProperty::NiSpecularProperty() NI_SPECULAR_PROPERTY_CONSTRUCT {}

NiSpecularProperty::~NiSpecularProperty() {}

void NiSpecularProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SPECULAR_PROPERTY_READ
}

void NiSpecularProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SPECULAR_PROPERTY_WRITE
}

string NiSpecularProperty::asString( bool verbose ) const {
	NI_SPECULAR_PROPERTY_STRING
}

void NiSpecularProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SPECULAR_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiSpecularProperty::GetRefs() const {
	NI_SPECULAR_PROPERTY_GETREFS
}

const Type & NiSpecularProperty::GetType() const {
	return TYPE;
};

ushort NiSpecularProperty::GetFlags() const {
   return flags;
}

void NiSpecularProperty::SetFlags( ushort n ) {
   flags = n;
}
