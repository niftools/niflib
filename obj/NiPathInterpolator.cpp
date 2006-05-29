/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPathInterpolator.h"
#include "NiPosData.h"
#include "NiFloatData.h"

//Definition of TYPE constant
const Type NiPathInterpolator::TYPE("NiPathInterpolator", &NI_PATH_INTERPOLATOR_PARENT::TYPE );

NiPathInterpolator::NiPathInterpolator() NI_PATH_INTERPOLATOR_CONSTRUCT {}

NiPathInterpolator::~NiPathInterpolator() {}

void NiPathInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_PATH_INTERPOLATOR_READ
}

void NiPathInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_PATH_INTERPOLATOR_WRITE
}

string NiPathInterpolator::asString( bool verbose ) const {
  NI_PATH_INTERPOLATOR_STRING
}

void NiPathInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_PATH_INTERPOLATOR_FIXLINKS
}

const Type & NiPathInterpolator::GetType() const {
  return TYPE;
};

