/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiAlphaProperty.h"

//Definition of TYPE constant
const Type NiAlphaProperty::TYPE("NiAlphaProperty", &NI_ALPHA_PROPERTY_PARENT::TYPE );

NiAlphaProperty::NiAlphaProperty() NI_ALPHA_PROPERTY_CONSTRUCT {}

NiAlphaProperty::~NiAlphaProperty() {}

void NiAlphaProperty::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_ALPHA_PROPERTY_READ
}

void NiAlphaProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_ALPHA_PROPERTY_WRITE
}

string NiAlphaProperty::asString( bool verbose ) const {
	NI_ALPHA_PROPERTY_STRING
}

void NiAlphaProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_ALPHA_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiAlphaProperty::GetRefs() const {
	NI_ALPHA_PROPERTY_GETREFS
}

const Type & NiAlphaProperty::GetType() const {
	return TYPE;
};

