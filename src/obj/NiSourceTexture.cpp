/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSourceTexture.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiPixelData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSourceTexture::TYPE("NiSourceTexture", &NI_SOURCE_TEXTURE_PARENT::TYPE );

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

bool NiSourceTexture::IsTextureExternal() const {
	return ( useExternal != 0 );
}

void NiSourceTexture::SetExternalTexture( string file_name ) {
	useExternal = 1;
	pixelData = NULL;
	this->originalFileName_.clear();

	fileName = file_name;
	unknownLink = NULL;
}

void NiSourceTexture::SetInternalTexture( string original_file_name, NiPixelData * pixel_data ) {
	useExternal = 0;
	fileName.clear();
	
	//TODO: Fix name problem with Unknown Byte in XML
	unknownByte = 0;
	originalFileName_ = original_file_name;
	pixelData = pixel_data;
}

string NiSourceTexture::GetTextureFileName() const {
	if ( IsTextureExternal() ) {
		return fileName;
	} else {
		return originalFileName_;
	}
}

Ref<NiPixelData> NiSourceTexture::GetPixelData() const {
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

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiSourceTexture"] = NiSourceTexture::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiSourceTexture::Create() {
	return new NiSourceTexture;
}
