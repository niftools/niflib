/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSpotLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSpotLight::TYPE("NiSpotLight", &NI_SPOT_LIGHT_PARENT::TYPE );

NiSpotLight::NiSpotLight() NI_SPOT_LIGHT_CONSTRUCT {}

NiSpotLight::~NiSpotLight() {}

void NiSpotLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSpotLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSpotLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSpotLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiSpotLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSpotLight::GetType() const {
	return TYPE;
};

float NiSpotLight::GetCutoffAngle() const {
	return cutoffAngle;
}

void NiSpotLight::SetCutoffAngle( float value ) {
	cutoffAngle = value;
}

float NiSpotLight::GetExponent() const {
	return exponent;
}

void NiSpotLight::SetExponent( float value ) {
	exponent = value;
}
