/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBooleanExtraData.h"

//Definition of TYPE constant
const Type NiBooleanExtraData::TYPE("NiBooleanExtraData", &NI_BOOLEAN_EXTRA_DATA_PARENT::TYPE );

NiBooleanExtraData::NiBooleanExtraData() NI_BOOLEAN_EXTRA_DATA_CONSTRUCT {}

NiBooleanExtraData::~NiBooleanExtraData() {}

void NiBooleanExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_BOOLEAN_EXTRA_DATA_READ
}

void NiBooleanExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_BOOLEAN_EXTRA_DATA_WRITE
}

string NiBooleanExtraData::asString( bool verbose ) const {
  NI_BOOLEAN_EXTRA_DATA_STRING
}

void NiBooleanExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_BOOLEAN_EXTRA_DATA_FIXLINKS
}

const Type & NiBooleanExtraData::GetType() const {
  return TYPE;
};

