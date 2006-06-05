/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiDitherProperty.h"

//Definition of TYPE constant
const Type NiDitherProperty::TYPE("NiDitherProperty", &NI_DITHER_PROPERTY_PARENT::TYPE );

NiDitherProperty::NiDitherProperty() NI_DITHER_PROPERTY_CONSTRUCT {}

NiDitherProperty::~NiDitherProperty() {}

void NiDitherProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DITHER_PROPERTY_READ
}

void NiDitherProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_DITHER_PROPERTY_WRITE
}

string NiDitherProperty::asString( bool verbose ) const {
	NI_DITHER_PROPERTY_STRING
}

void NiDitherProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DITHER_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiDitherProperty::GetRefs() const {
	NI_DITHER_PROPERTY_GETREFS
}

const Type & NiDitherProperty::GetType() const {
	return TYPE;
};

