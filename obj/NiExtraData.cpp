/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiExtraData.h"

//Definition of TYPE constant
const Type NiExtraData::TYPE("NiExtraData", &NI_EXTRA_DATA_PARENT::TYPE );

NiExtraData::NiExtraData() NI_EXTRA_DATA_CONSTRUCT {}

NiExtraData::~NiExtraData() {}

void NiExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_EXTRA_DATA_READ
}

void NiExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_EXTRA_DATA_WRITE
}

string NiExtraData::asString( bool verbose ) const {
  NI_EXTRA_DATA_STRING
}

void NiExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_EXTRA_DATA_FIXLINKS
}

const Type & NiExtraData::GetType() const {
  return TYPE;
};

