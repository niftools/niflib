/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiFogProperty.h"

//Definition of TYPE constant
const Type NiFogProperty::TYPE("NiFogProperty", &NI_FOG_PROPERTY_PARENT::TYPE );

NiFogProperty::NiFogProperty() NI_FOG_PROPERTY_CONSTRUCT {}

NiFogProperty::~NiFogProperty() {}

void NiFogProperty::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_FOG_PROPERTY_READ
}

void NiFogProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_FOG_PROPERTY_WRITE
}

string NiFogProperty::asString( bool verbose ) const {
  NI_FOG_PROPERTY_STRING
}

void NiFogProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_FOG_PROPERTY_FIXLINKS
}

const Type & NiFogProperty::GetType() const {
  return TYPE;
};

