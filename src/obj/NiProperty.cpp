/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiProperty::TYPE("NiProperty", &NI_PROPERTY_PARENT::TypeConst() );

NiProperty::NiProperty() NI_PROPERTY_CONSTRUCT {}

NiProperty::~NiProperty() {}

void NiProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PROPERTY_READ
}

void NiProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PROPERTY_WRITE
}

string NiProperty::asString( bool verbose ) const {
	NI_PROPERTY_STRING
}

void NiProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiProperty::GetRefs() const {
	NI_PROPERTY_GETREFS
}

const Type & NiProperty::GetType() const {
	return TYPE;
};

