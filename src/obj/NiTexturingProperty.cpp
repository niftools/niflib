/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTexturingProperty.h"
#include "../../include/gen/TexDesc.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTexturingProperty::TYPE("NiTexturingProperty", &NI_TEXTURING_PROPERTY_PARENT::TYPE );

NiTexturingProperty::NiTexturingProperty() NI_TEXTURING_PROPERTY_CONSTRUCT {}

NiTexturingProperty::~NiTexturingProperty() {}

void NiTexturingProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTexturingProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTexturingProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTexturingProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTexturingProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTexturingProperty::GetType() const {
	return TYPE;
};

ApplyMode NiTexturingProperty::GetApplyMode() const {
	return applyMode;
}

void NiTexturingProperty::SetApplyMode( ApplyMode new_val ) {
	applyMode = new_val;
}

int NiTexturingProperty::GetTextureCount() const {
	//TODO:  Create a built in type for this array of textures so it can be a real array again?
	int count = 0;
	if ( hasBaseTexture ) { count++; }
	if ( hasBumpMapTexture ) { count++; }
	if ( hasDarkTexture ) { count++; }
	if ( hasDecal0Texture ) { count++; }
	if ( hasDecal1Texture ) { count++; }
	if ( hasDetailTexture ) { count++; }
	if ( hasGlossTexture ) { count++; }
	if ( hasGlowTexture ) { count++; }
	return count;
}

int NiTexturingProperty::GetShaderTextureCount() const {
	return int(shaderTextures.size());
}

TexDesc NiTexturingProperty::GetTexture( int n ) const {
	//TODO:  Create a built in type for this array of textures so it can be a real array again?
	//Copy the values to the right texture
	switch (n) {
		case BASE_MAP:
			return baseTexture;
		case DARK_MAP:
			return darkTexture;
		case DETAIL_MAP:
			return detailTexture;
		case GLOSS_MAP:
			return glossTexture;
		case GLOW_MAP:
			return glowTexture;
		case BUMP_MAP:
			return bumpMapTexture;
		case DECAL_0_MAP:
			return decal0Texture;
		case DECAL_1_MAP:
			return decal1Texture;
	};

	//If we get here, an invalid texture was requested.
	throw runtime_error("Invalid texture requested.");
}

TexDesc NiTexturingProperty::GetShaderTexture( int n ) const {
	return shaderTextures[n].textureData;
}

float NiTexturingProperty::GetLumaOffset() const {
	return bumpMapLumaOffset;
}

void NiTexturingProperty::SetLumaOffset( float new_val ) {
	bumpMapLumaOffset = new_val;
}

float NiTexturingProperty::GetLumaScale() const {
	return bumpMapLumaScale;
}

void NiTexturingProperty::SetLumaScale( float new_val ) {
	bumpMapLumaScale = new_val;
}

Matrix22 NiTexturingProperty::GetBumpMapMatrix() const {
	return bumpMapMatrix;
}

void NiTexturingProperty::SetBumpMapMatrix( Matrix22 & new_val ) {
	bumpMapMatrix = new_val;
}

void NiTexturingProperty::SetTextureCount( int new_count ) {

	if ( new_count < int(textureCount) ) {
		for ( int i = int(textureCount); i > new_count; --i ) {
			ClearTexture(i);
		}
	}
}

void NiTexturingProperty::SetShaderTextureCount( int new_count ) {
	//Resize array
	shaderTextures.resize( new_count );
}

void NiTexturingProperty::SetTexture( int n, TexDesc & new_val ) {
	//Make sure index is not out of range
	
	if ( n < 0 || n > int(textureCount) ) {
		throw runtime_error("SetTexture - Index out of range.  Call SetTextureCount to resize.");
	}

	//TODO:  Create a built in type for this array of textures so it can be a real array again?
	//Copy the values to the right texture
	switch (n) {
		case BASE_MAP:
			hasBaseTexture = true;
			baseTexture = new_val;
			break;
		case DARK_MAP:
			hasDarkTexture = true;
			darkTexture = new_val;
			break;
		case DETAIL_MAP:
			hasDetailTexture = true;
			detailTexture = new_val;
			break;
		case GLOSS_MAP:
			hasGlossTexture = true;
			glossTexture = new_val;
			break;
		case GLOW_MAP:
			hasGlowTexture = true;
			glowTexture = new_val;
			break;
		case BUMP_MAP:
			hasBumpMapTexture = true;
			bumpMapTexture = new_val;
			break;
		case DECAL_0_MAP:
			hasDecal0Texture = true;
			decal0Texture = new_val;
			break;
		case DECAL_1_MAP:
			hasDecal1Texture = true;
			decal1Texture = new_val;
			break;
	};
}

void NiTexturingProperty::SetShaderTexture( int n, TexDesc & new_val ) {
	//Make sure index is not out of range
	if ( n < 0 || n > int(shaderTextures.size()) ) {
		throw runtime_error("SetShaderTexture - Index out of range.  Call SetShaderTextureCount to resize.");
	}

	//Copy the values
	shaderTextures[n].textureData = new_val;
}

bool NiTexturingProperty::HasTexture( int n ) const {
	switch (n) {
		case BASE_MAP:
			return hasBaseTexture;
		case DARK_MAP:
			return hasDarkTexture;
		case DETAIL_MAP:
			return hasDetailTexture;
		case GLOSS_MAP:
			return hasGlossTexture;
		case GLOW_MAP:
			return hasGlowTexture;
		case BUMP_MAP:
			return hasBumpMapTexture;
		case DECAL_0_MAP:
			return hasDecal0Texture;
		case DECAL_1_MAP:
			return hasDecal1Texture;
		default:
			throw runtime_error("You have specified an invalid texture type.");
	};
}

void NiTexturingProperty::ClearTexture( int n ) {
	switch (n) {
		case BASE_MAP:
			hasBaseTexture = false;
			baseTexture.source = NULL;
			break;
		case DARK_MAP:
			hasDarkTexture = false;
			darkTexture.source = NULL;
			break;
		case DETAIL_MAP:
			hasDetailTexture = false;
			detailTexture.source = NULL;
			break;
		case GLOSS_MAP:
			hasGlossTexture = false;
			glossTexture.source = NULL;
			break;
		case GLOW_MAP:
			hasGlowTexture = false;
			glowTexture.source = NULL;
			break;
		case BUMP_MAP:
			hasBumpMapTexture = false;
			bumpMapTexture.source = NULL;
			break;
		case DECAL_0_MAP:
			hasDecal0Texture = false;
			decal0Texture.source = NULL;
			break;
		case DECAL_1_MAP:
			hasDecal1Texture = false;
			decal1Texture.source = NULL;
			break;
	};
}
