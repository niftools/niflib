/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "AKeyedData.h"

//Definition of TYPE constant
const Type AKeyedData::TYPE("AKeyedData", &A_KEYED_DATA_PARENT::TYPE );

AKeyedData::AKeyedData() A_KEYED_DATA_CONSTRUCT {}

AKeyedData::~AKeyedData() {}

void AKeyedData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  A_KEYED_DATA_READ
}

void AKeyedData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  A_KEYED_DATA_WRITE
}

string AKeyedData::asString( bool verbose ) const {
  A_KEYED_DATA_STRING
}

void AKeyedData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  A_KEYED_DATA_FIXLINKS
}

const Type & AKeyedData::GetType() const {
  return TYPE;
};

