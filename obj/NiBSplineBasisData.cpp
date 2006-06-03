/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBSplineBasisData.h"

//Definition of TYPE constant
const Type NiBSplineBasisData::TYPE("NiBSplineBasisData", &NI_B_SPLINE_BASIS_DATA_PARENT::TYPE );

NiBSplineBasisData::NiBSplineBasisData() NI_B_SPLINE_BASIS_DATA_CONSTRUCT {}

NiBSplineBasisData::~NiBSplineBasisData() {}

void NiBSplineBasisData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_B_SPLINE_BASIS_DATA_READ
}

void NiBSplineBasisData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_B_SPLINE_BASIS_DATA_WRITE
}

string NiBSplineBasisData::asString( bool verbose ) const {
  NI_B_SPLINE_BASIS_DATA_STRING
}

void NiBSplineBasisData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_B_SPLINE_BASIS_DATA_FIXLINKS
}

const Type & NiBSplineBasisData::GetType() const {
  return TYPE;
};

