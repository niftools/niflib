/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPalette::TYPE("NiPalette", &NI_PALETTE_PARENT::TypeConst() );

NiPalette::NiPalette() NI_PALETTE_CONSTRUCT {}

NiPalette::~NiPalette() {}

void NiPalette::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPalette::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPalette::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPalette::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPalette::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPalette::GetType() const {
	return TYPE;
};

vector<Color4> NiPalette::GetPalette() const {
	vector<Color4> color_pal(256);

	for ( uint i = 0; i < 256; ++i ) {
		
		color_pal[i].r = float(palette[i][0]) / 255.0f;
		color_pal[i].g = float(palette[i][1]) / 255.0f;
		color_pal[i].b = float(palette[i][2]) / 255.0f;
		color_pal[i].a = float(palette[i][3]) / 255.0f;
	}

	return color_pal;
}

void NiPalette::SetPalette( const vector<Color4> & new_pal ) {
	if ( new_pal.size() != 256 ) {
		throw runtime_error( "Palette size must be 256" );
	}

	for ( uint i = 0; i < 256; ++i ) {
		palette[i][0] = int( new_pal[i].r * 255.0f );
		palette[i][1] = int( new_pal[i].g * 255.0f );
		palette[i][2] = int( new_pal[i].b * 255.0f );
		palette[i][3] = int( new_pal[i].a * 255.0f );
	}
}
