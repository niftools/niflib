/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiDirectionalLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDirectionalLight::TYPE("NiDirectionalLight", &NI_DIRECTIONAL_LIGHT_PARENT::TypeConst() );

NiDirectionalLight::NiDirectionalLight() NI_DIRECTIONAL_LIGHT_CONSTRUCT {}

NiDirectionalLight::~NiDirectionalLight() {}

void NiDirectionalLight::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DIRECTIONAL_LIGHT_READ
}

void NiDirectionalLight::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_DIRECTIONAL_LIGHT_WRITE
}

string NiDirectionalLight::asString( bool verbose ) const {
	NI_DIRECTIONAL_LIGHT_STRING
}

void NiDirectionalLight::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DIRECTIONAL_LIGHT_FIXLINKS
}

list<NiObjectRef> NiDirectionalLight::GetRefs() const {
	NI_DIRECTIONAL_LIGHT_GETREFS
}

const Type & NiDirectionalLight::GetType() const {
	return TYPE;
};

