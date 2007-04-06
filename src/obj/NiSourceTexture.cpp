/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSourceTexture.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiPixelData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSourceTexture::TYPE("NiSourceTexture", &NI_SOURCE_TEXTURE_PARENT::TypeConst() );

NiSourceTexture::NiSourceTexture() NI_SOURCE_TEXTURE_CONSTRUCT {}

NiSourceTexture::~NiSourceTexture() {}

void NiSourceTexture::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSourceTexture::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSourceTexture::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSourceTexture::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiSourceTexture::GetRefs() const {
	return InternalGetRefs();
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

const Type & NiSourceTexture::TypeConst() {
	return TYPE;
}
