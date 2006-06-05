/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiDefaultAVObjectPalette.h"
#include "../gen/AVObject.h"
#include "NiAVObject.h"

//Definition of TYPE constant
const Type NiDefaultAVObjectPalette::TYPE("NiDefaultAVObjectPalette", &NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT::TYPE );

NiDefaultAVObjectPalette::NiDefaultAVObjectPalette() NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT {}

NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette() {}

void NiDefaultAVObjectPalette::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DEFAULT_A_V_OBJECT_PALETTE_READ
}

void NiDefaultAVObjectPalette::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_DEFAULT_A_V_OBJECT_PALETTE_WRITE
}

string NiDefaultAVObjectPalette::asString( bool verbose ) const {
	NI_DEFAULT_A_V_OBJECT_PALETTE_STRING
}

void NiDefaultAVObjectPalette::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DEFAULT_A_V_OBJECT_PALETTE_FIXLINKS
}

list<NiObjectRef> NiDefaultAVObjectPalette::GetRefs() const {
	NI_DEFAULT_A_V_OBJECT_PALETTE_GETREFS
}

const Type & NiDefaultAVObjectPalette::GetType() const {
	return TYPE;
};

