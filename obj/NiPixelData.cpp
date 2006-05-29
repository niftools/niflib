/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPixelData.h"
#include "NiPalette.h"

//Definition of TYPE constant
const Type NiPixelData::TYPE("NiPixelData", &NI_PIXEL_DATA_PARENT::TYPE );

NiPixelData::NiPixelData() NI_PIXEL_DATA_CONSTRUCT {}

NiPixelData::~NiPixelData() {}

void NiPixelData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_PIXEL_DATA_READ
}

void NiPixelData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PIXEL_DATA_WRITE
}

string NiPixelData::asString( bool verbose ) const {
	NI_PIXEL_DATA_STRING
}

void NiPixelData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_PIXEL_DATA_FIXLINKS
}

