/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiColorData.h"

//Definition of TYPE constant
const Type NiColorData::TYPE("NiColorData", &NI_COLOR_DATA_PARENT::TYPE );

NiColorData::NiColorData() NI_COLOR_DATA_CONSTRUCT {}

NiColorData::~NiColorData() {}

void NiColorData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_COLOR_DATA_READ
}

void NiColorData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_COLOR_DATA_WRITE
}

string NiColorData::asString( bool verbose ) const {
  NI_COLOR_DATA_STRING
}

void NiColorData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_COLOR_DATA_FIXLINKS
}

const Type & NiColorData::GetType() const {
  return TYPE;
};

