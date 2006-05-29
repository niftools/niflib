/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSourceTexture.h"
#include "NiPixelData.h"

//Definition of TYPE constant
const Type NiSourceTexture::TYPE("NiSourceTexture", &NI_SOURCE_TEXTURE_PARENT::TYPE );

NiSourceTexture::NiSourceTexture() NI_SOURCE_TEXTURE_CONSTRUCT {}

NiSourceTexture::~NiSourceTexture() {}

void NiSourceTexture::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_SOURCE_TEXTURE_READ
}

void NiSourceTexture::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_SOURCE_TEXTURE_WRITE
}

string NiSourceTexture::asString( bool verbose ) const {
	NI_SOURCE_TEXTURE_STRING
}

void NiSourceTexture::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_SOURCE_TEXTURE_FIXLINKS
}

