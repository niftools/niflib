/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiMorphData.h"
#include "gen/Morph.h"

//Definition of TYPE constant
const Type NiMorphData::TYPE("NiMorphData", &NI_MORPH_DATA_PARENT::TYPE );

NiMorphData::NiMorphData() NI_MORPH_DATA_CONSTRUCT {}

NiMorphData::~NiMorphData() {}

void NiMorphData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_MORPH_DATA_READ
}

void NiMorphData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_MORPH_DATA_WRITE
}

string NiMorphData::asString( bool verbose ) const {
  NI_MORPH_DATA_STRING
}

void NiMorphData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_MORPH_DATA_FIXLINKS
}

const Type & NiMorphData::GetType() const {
  return TYPE;
};

