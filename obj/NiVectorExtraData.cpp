/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiVectorExtraData.h"

//Definition of TYPE constant
const Type NiVectorExtraData::TYPE("NiVectorExtraData", &NI_VECTOR_EXTRA_DATA_PARENT::TYPE );

NiVectorExtraData::NiVectorExtraData() NI_VECTOR_EXTRA_DATA_CONSTRUCT {}

NiVectorExtraData::~NiVectorExtraData() {}

void NiVectorExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_VECTOR_EXTRA_DATA_READ
}

void NiVectorExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_VECTOR_EXTRA_DATA_WRITE
}

string NiVectorExtraData::asString( bool verbose ) const {
  NI_VECTOR_EXTRA_DATA_STRING
}

void NiVectorExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_VECTOR_EXTRA_DATA_FIXLINKS
}

const Type & NiVectorExtraData::GetType() const {
  return TYPE;
};

