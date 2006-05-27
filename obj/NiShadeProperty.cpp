/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiShadeProperty.h"

//Definition of TYPE constant
const Type NiShadeProperty::TYPE("NiShadeProperty", &NI_SHADE_PROPERTY_PARENT::TYPE );

NiShadeProperty::NiShadeProperty() NI_SHADE_PROPERTY_CONSTRUCT {}

NiShadeProperty::~NiShadeProperty() {}

void NiShadeProperty::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_SHADE_PROPERTY_READ
}

void NiShadeProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_SHADE_PROPERTY_WRITE
}

string NiShadeProperty::asString( bool verbose ) const {
	NI_SHADE_PROPERTY_STRING
}

void NiShadeProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_SHADE_PROPERTY_FIXLINKS
}

