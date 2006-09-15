/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLight::TYPE("NiLight", &NI_LIGHT_PARENT::TypeConst() );

NiLight::NiLight() NI_LIGHT_CONSTRUCT {}

NiLight::~NiLight() {}

void NiLight::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LIGHT_READ
}

void NiLight::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_LIGHT_WRITE
}

string NiLight::asString( bool verbose ) const {
	NI_LIGHT_STRING
}

void NiLight::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LIGHT_FIXLINKS
}

list<NiObjectRef> NiLight::GetRefs() const {
	NI_LIGHT_GETREFS
}

const Type & NiLight::GetType() const {
	return TYPE;
};

float NiLight::GetDimmer() const {
	return dimmer;
}

void NiLight::SetDimmer( float value ) {
	dimmer = value;
}

Color3 NiLight::GetAmbientColor() const {
	return ambientColor;
}

void NiLight::SetAmbientColor( Color3 value ) {
	ambientColor = value;
}

Color3 NiLight::GetDiffuseColor() const {
	return diffuseColor;
}

void NiLight::SetDiffuseColor( Color3 value ) {
	diffuseColor = value;
}

Color3 NiLight::GetSpecularColor() const {
	return specularColor;
}

void NiLight::SetSpecularColor( Color3 value ) {
	specularColor = value;
}

