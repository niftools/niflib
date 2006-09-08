/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTextureEffect.h"
#include "NiSourceTexture.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureEffect::TYPE("NiTextureEffect", &NI_TEXTURE_EFFECT_PARENT::TypeConst() );

NiTextureEffect::NiTextureEffect() NI_TEXTURE_EFFECT_CONSTRUCT {}

NiTextureEffect::~NiTextureEffect() {}

void NiTextureEffect::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURE_EFFECT_READ
}

void NiTextureEffect::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TEXTURE_EFFECT_WRITE
}

string NiTextureEffect::asString( bool verbose ) const {
	NI_TEXTURE_EFFECT_STRING
}

void NiTextureEffect::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURE_EFFECT_FIXLINKS
}

list<NiObjectRef> NiTextureEffect::GetRefs() const {
	NI_TEXTURE_EFFECT_GETREFS
}

const Type & NiTextureEffect::GetType() const {
	return TYPE;
};

Matrix33 NiTextureEffect::GetModelProjectionMatrix() const {
	return modelProjectionMatrix;
}

void NiTextureEffect::SetModelProjectionMatrix( Matrix33 value ) {
	modelProjectionMatrix = value;
}

Vector3 NiTextureEffect::GetModelProjectionTransform() const {
	return modelProjectionTransform;
}

void NiTextureEffect::SetModelProjectionTransform( Vector3 value ) {
	modelProjectionTransform = value;
}

uint NiTextureEffect::GetTextureFiltering() const {
	return textureFiltering;
}

void NiTextureEffect::SetTextureFiltering( uint value ) {
	textureFiltering = value;
}

TexClampMode NiTextureEffect::GetTextureClamping() const {
	return textureClamping;
}

void NiTextureEffect::SetTextureClamping( TexClampMode value ) {
	textureClamping = value;
}

uint NiTextureEffect::GetTextureType() const {
	return textureType;
}

void NiTextureEffect::SetTextureType( uint value ) {
	textureType = value;
}

uint NiTextureEffect::GetCoordinateGenerationType() const {
	return coordinateGenerationType;
}

void NiTextureEffect::SetCoordinateGenerationType( uint value ) {
	coordinateGenerationType = value;
}

Ref<NiSourceTexture > NiTextureEffect::GetSourceTexture() const {
	return sourceTexture;
}

void NiTextureEffect::SetSourceTexture( Ref<NiSourceTexture > value ) {
	sourceTexture = value;
}

byte NiTextureEffect::GetClippingPlane() const {
	return clippingPlane;
}

void NiTextureEffect::SetClippingPlane( byte value ) {
	clippingPlane = value;
}

ushort NiTextureEffect::GetPs2L() const {
	return ps2L;
}

void NiTextureEffect::SetPs2L( ushort value ) {
	ps2L = value;
}

ushort NiTextureEffect::GetPs2K() const {
	return ps2K;
}

void NiTextureEffect::SetPs2K( ushort value ) {
	ps2K = value;
}

