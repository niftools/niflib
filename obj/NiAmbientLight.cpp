/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiAmbientLight.h"

//Definition of TYPE constant
const Type NiAmbientLight::TYPE("NiAmbientLight", &NI_AMBIENT_LIGHT_PARENT::TYPE );

NiAmbientLight::NiAmbientLight() NI_AMBIENT_LIGHT_CONSTRUCT {}

NiAmbientLight::~NiAmbientLight() {}

void NiAmbientLight::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_AMBIENT_LIGHT_READ
}

void NiAmbientLight::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_AMBIENT_LIGHT_WRITE
}

string NiAmbientLight::asString( bool verbose ) const {
  NI_AMBIENT_LIGHT_STRING
}

void NiAmbientLight::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_AMBIENT_LIGHT_FIXLINKS
}

const Type & NiAmbientLight::GetType() const {
  return TYPE;
};

