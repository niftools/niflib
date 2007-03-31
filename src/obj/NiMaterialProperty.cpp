/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMaterialProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMaterialProperty::TYPE("NiMaterialProperty", &NI_MATERIAL_PROPERTY_PARENT::TypeConst() );

NiMaterialProperty::NiMaterialProperty() NI_MATERIAL_PROPERTY_CONSTRUCT {}

NiMaterialProperty::~NiMaterialProperty() {}

void NiMaterialProperty::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiMaterialProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiMaterialProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMaterialProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiMaterialProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMaterialProperty::GetType() const {
	return TYPE;
};

unsigned short NiMaterialProperty::GetFlags() const {
	return flags;
}

void NiMaterialProperty::SetFlags( unsigned short n ) {
	flags = n;
}

float NiMaterialProperty::GetTransparency() const {
	return alpha;
}

void NiMaterialProperty::SetTransparency( float n ) {
	alpha = n;
}

float NiMaterialProperty::GetGlossiness() const {
	return glossiness;
}

void NiMaterialProperty::SetGlossiness( float n ) {
	glossiness = n;
}

Color3 NiMaterialProperty::GetAmbientColor() const {
	return ambientColor;
}

void NiMaterialProperty::SetAmbientColor( const Color3 & n ) {
	ambientColor = n;
}

Color3 NiMaterialProperty::GetDiffuseColor() const {
	return diffuseColor;
}

void NiMaterialProperty::SetDiffuseColor( const Color3 & n ) {
	diffuseColor = n;
}

Color3 NiMaterialProperty::GetEmissiveColor() const {
	return emissiveColor;
}

void NiMaterialProperty::SetEmissiveColor( const Color3 & n ) {
	emissiveColor = n;
}

Color3 NiMaterialProperty::GetSpecularColor() const {
	return specularColor;
}

void NiMaterialProperty::SetSpecularColor( const Color3 & n ) {
	specularColor = n;
}

const Type & NiMaterialProperty::TypeConst() {
	return TYPE;
}
