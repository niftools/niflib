/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiZBufferProperty.h"

//Definition of TYPE constant
const Type NiZBufferProperty::TYPE("NiZBufferProperty", &NI_Z_BUFFER_PROPERTY_PARENT::TYPE );

NiZBufferProperty::NiZBufferProperty() NI_Z_BUFFER_PROPERTY_CONSTRUCT {}

NiZBufferProperty::~NiZBufferProperty() {}

void NiZBufferProperty::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_Z_BUFFER_PROPERTY_READ
}

void NiZBufferProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_Z_BUFFER_PROPERTY_WRITE
}

string NiZBufferProperty::asString( bool verbose ) const {
	NI_Z_BUFFER_PROPERTY_STRING
}

void NiZBufferProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_Z_BUFFER_PROPERTY_FIXLINKS
}

const Type & NiZBufferProperty::GetType() const {
	return TYPE;
};

