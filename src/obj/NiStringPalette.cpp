/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStringPalette.h"
#include "../../include/gen/StringPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringPalette::TYPE("NiStringPalette", &NI_STRING_PALETTE_PARENT::TypeConst() );

NiStringPalette::NiStringPalette() NI_STRING_PALETTE_CONSTRUCT {}

NiStringPalette::~NiStringPalette() {}

void NiStringPalette::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STRING_PALETTE_READ
}

void NiStringPalette::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_STRING_PALETTE_WRITE
}

string NiStringPalette::asString( bool verbose ) const {
	NI_STRING_PALETTE_STRING
}

void NiStringPalette::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STRING_PALETTE_FIXLINKS
}

list<NiObjectRef> NiStringPalette::GetRefs() const {
	NI_STRING_PALETTE_GETREFS
}

const Type & NiStringPalette::GetType() const {
	return TYPE;
};

string NiStringPalette::GetPaletteString() const {
	return palette.palette;
}
	
void NiStringPalette::SetPaletteString( const string & n ) {
	palette.palette = n;
}

string NiStringPalette::GetSubStr( short offset ) const {
	string out;
	
	// -1 is a null offset
	if ( offset == -1 ) {
		return out;
	}

	for ( uint i = offset; i < palette.palette.size(); ++i ) {
		if ( palette.palette[i] == '\0' ) {
			break;
		}
		out.push_back( palette.palette[i] );
	}

	return out;
}

unsigned int NiStringPalette::AddSubStr( const string & n ) {
	//Search for the string
   //  When searching for strings also search for ending null.
	uint offset = (uint)palette.palette.find( n.c_str(), 0, n.size()+1 );
	
	//If string was not found, append it
	if ( offset == 0xFFFFFFFF ) {
		offset = (uint)palette.palette.size();
		palette.palette.append( n + '\0' );
	}

	//Return the offset where the string was found or appended
	return offset;
}