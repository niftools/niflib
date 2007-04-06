/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPointLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPointLight::TYPE("NiPointLight", &NI_POINT_LIGHT_PARENT::TypeConst() );

NiPointLight::NiPointLight() NI_POINT_LIGHT_CONSTRUCT {}

NiPointLight::~NiPointLight() {}

void NiPointLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPointLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPointLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPointLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPointLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPointLight::GetType() const {
	return TYPE;
};

float NiPointLight::GetConstantAttenuation() const {
	return constantAttenuation;
}

void NiPointLight::SetConstantAttenuation( float value ) {
	constantAttenuation = value;
}

float NiPointLight::GetLinearAttenuation() const {
	return linearAttenuation;
}

void NiPointLight::SetLinearAttenuation( float value ) {
	linearAttenuation = value;
}

float NiPointLight::GetQuadraticAttenuation() const {
	return quadraticAttenuation;
}

void NiPointLight::SetQuadraticAttenuation( float value ) {
	quadraticAttenuation = value;
}

const Type & NiPointLight::TypeConst() {
	return TYPE;
}
