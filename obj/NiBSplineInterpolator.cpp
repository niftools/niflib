/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBSplineInterpolator.h"

//Definition of TYPE constant
const Type NiBSplineInterpolator::TYPE("NiBSplineInterpolator", &NI_B_SPLINE_INTERPOLATOR_PARENT::TYPE );

NiBSplineInterpolator::NiBSplineInterpolator() NI_B_SPLINE_INTERPOLATOR_CONSTRUCT {}

NiBSplineInterpolator::~NiBSplineInterpolator() {}

void NiBSplineInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_B_SPLINE_INTERPOLATOR_READ
}

void NiBSplineInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_B_SPLINE_INTERPOLATOR_WRITE
}

string NiBSplineInterpolator::asString( bool verbose ) const {
  NI_B_SPLINE_INTERPOLATOR_STRING
}

void NiBSplineInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_B_SPLINE_INTERPOLATOR_FIXLINKS
}

const Type & NiBSplineInterpolator::GetType() const {
  return TYPE;
};

