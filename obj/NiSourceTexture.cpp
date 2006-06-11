/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSourceTexture.h"
#include "NiObject.h"
#include "NiPixelData.h"

//Definition of TYPE constant
const Type NiSourceTexture::TYPE("NiSourceTexture", &NI_SOURCE_TEXTURE_PARENT::TYPE );

NiSourceTexture::NiSourceTexture() NI_SOURCE_TEXTURE_CONSTRUCT {}

NiSourceTexture::~NiSourceTexture() {}

void NiSourceTexture::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SOURCE_TEXTURE_READ
}

void NiSourceTexture::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SOURCE_TEXTURE_WRITE
}

string NiSourceTexture::asString( bool verbose ) const {
	NI_SOURCE_TEXTURE_STRING
}

void NiSourceTexture::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SOURCE_TEXTURE_FIXLINKS
}

list<NiObjectRef> NiSourceTexture::GetRefs() const {
	NI_SOURCE_TEXTURE_GETREFS
}

const Type & NiSourceTexture::GetType() const {
	return TYPE;
};

bool NiSourceTexture::IsTextureExternal () {
	return ( useExternal != 0 );
}

void NiSourceTexture::SetExternalTexture( string file_name, const Ref<NiObject> & unk_link ) {
	useExternal = 1;
	pixelData = NULL;
	this->originalFileName_.clear();

	fileName = file_name;
	unknownLink = unk_link;
}


void NiSourceTexture::SetInternalTexture( byte unk_byte, string original_file_name, const Ref<NiPixelData> & pixel_data ) {
	useExternal = 0;
	fileName.clear();
	
	//TODO: Fix name problem with Unknown Byte in XML
	unknownByte = unk_byte;
	originalFileName_ = original_file_name;
	pixelData = pixel_data;
}

string NiSourceTexture::GetExternalFileName() const {
	return fileName;
}

Ref<NiObject> NiSourceTexture::GetExternalUnknownLink() const {
	return unknownLink;
}

byte NiSourceTexture::GetInternalUnknownByte() const {
	return unknownByte;
}

string NiSourceTexture::GetInternalOriginalFileName() const {
	return originalFileName_;
}

Ref<NiPixelData> NiSourceTexture::GetInternalPixelData() const {
	return pixelData;
}

PixelLayout NiSourceTexture::GetPixelLayout() const {
	return pixelLayout;
}

void NiSourceTexture::SetPixelLayout( PixelLayout n ) {
	pixelLayout = n;
}

MipMapFormat NiSourceTexture::GetMipMapFormat() const {
	return useMipmaps;
}

void NiSourceTexture::SetMipMapFormat( MipMapFormat n ) {
	useMipmaps = n;
}

AlphaFormat NiSourceTexture::GetAlphaFormat() const {
	return alphaFormat;
}

void NiSourceTexture::SetAlphaFormat( AlphaFormat n ) {
	alphaFormat = n;
}

//TODO: Fix name problem with Unknown Byte in XML
//byte NiSourceTexture::GetUnknownByte2() const;
//SNiSourceTexture::etUnknownByte2( byte n );
//
//byte NiSourceTexture::GetUnknownByte3() const;
//NiSourceTexture::SetUnknownByte3( byte n );