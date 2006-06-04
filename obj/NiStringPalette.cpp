/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiStringPalette.h"
#include "gen/StringPalette.h"

//Definition of TYPE constant
const Type NiStringPalette::TYPE("NiStringPalette", &NI_STRING_PALETTE_PARENT::TYPE );

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

