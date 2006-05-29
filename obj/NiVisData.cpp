/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiVisData.h"

//Definition of TYPE constant
const Type NiVisData::TYPE("NiVisData", &NI_VIS_DATA_PARENT::TYPE );

NiVisData::NiVisData() NI_VIS_DATA_CONSTRUCT {}

NiVisData::~NiVisData() {}

void NiVisData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_VIS_DATA_READ
}

void NiVisData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_VIS_DATA_WRITE
}

string NiVisData::asString( bool verbose ) const {
  NI_VIS_DATA_STRING
}

void NiVisData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_VIS_DATA_FIXLINKS
}

const Type & NiVisData::GetType() const {
  return TYPE;
};

