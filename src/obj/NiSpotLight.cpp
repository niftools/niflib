/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSpotLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSpotLight::TYPE("NiSpotLight", &NI_SPOT_LIGHT_PARENT::TypeConst() );

NiSpotLight::NiSpotLight() NI_SPOT_LIGHT_CONSTRUCT {}

NiSpotLight::~NiSpotLight() {}

void NiSpotLight::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiSpotLight::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiSpotLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSpotLight::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

