/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiAlphaProperty.h"

//Definition of TYPE constant
const Type NiAlphaProperty::TYPE("NiAlphaProperty", &NI_ALPHA_PROPERTY_PARENT::TypeConst() );

NiAlphaProperty::NiAlphaProperty() NI_ALPHA_PROPERTY_CONSTRUCT {}

NiAlphaProperty::~NiAlphaProperty() {}

void NiAlphaProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ALPHA_PROPERTY_READ
}

void NiAlphaProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_ALPHA_PROPERTY_WRITE
}

string NiAlphaProperty::asString( bool verbose ) const {
	NI_ALPHA_PROPERTY_STRING
}

void NiAlphaProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ALPHA_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiAlphaProperty::GetRefs() const {
	NI_ALPHA_PROPERTY_GETREFS
}

const Type & NiAlphaProperty::GetType() const {
	return TYPE;
};

ushort NiAlphaProperty::GetFlags() const {
	return flags;
}

void NiAlphaProperty::SetFlags( ushort n ) {
	flags = n;
}

byte NiAlphaProperty::GetAlphaTestThreshold() const {
	return threshold;
}

void NiAlphaProperty::SetAlphaTestThreshold( byte n ) {
	threshold = n;
}

