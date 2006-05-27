/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPalette.h"

//Definition of TYPE constant
const Type NiPalette::TYPE("NiPalette", &NI_PALETTE_PARENT::TYPE );

NiPalette::NiPalette() NI_PALETTE_CONSTRUCT {}

NiPalette::~NiPalette() {}

void NiPalette::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_PALETTE_READ
}

void NiPalette::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PALETTE_WRITE
}

string NiPalette::asString( bool verbose ) const {
	NI_PALETTE_STRING
}

void NiPalette::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_PALETTE_FIXLINKS
}

