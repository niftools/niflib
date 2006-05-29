/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiProperty.h"

//Definition of TYPE constant
const Type NiProperty::TYPE("NiProperty", &NI_PROPERTY_PARENT::TYPE );

NiProperty::NiProperty() NI_PROPERTY_CONSTRUCT {}

NiProperty::~NiProperty() {}

void NiProperty::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_PROPERTY_READ
}

void NiProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PROPERTY_WRITE
}

string NiProperty::asString( bool verbose ) const {
	NI_PROPERTY_STRING
}

void NiProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_PROPERTY_FIXLINKS
}

