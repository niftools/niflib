/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLight::TYPE("NiLight", &NI_LIGHT_PARENT::TypeConst() );

NiLight::NiLight() NI_LIGHT_CONSTRUCT {}

NiLight::~NiLight() {}

void NiLight::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiLight::GetRefs() const {
	return InternalGetRefs();
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

