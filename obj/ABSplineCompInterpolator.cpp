/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "ABSplineCompInterpolator.h"

//Definition of TYPE constant
const Type ABSplineCompInterpolator::TYPE("ABSplineCompInterpolator", &A_B_SPLINE_COMP_INTERPOLATOR_PARENT::TYPE );

ABSplineCompInterpolator::ABSplineCompInterpolator() A_B_SPLINE_COMP_INTERPOLATOR_CONSTRUCT {}

ABSplineCompInterpolator::~ABSplineCompInterpolator() {}

void ABSplineCompInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	A_B_SPLINE_COMP_INTERPOLATOR_READ
}

void ABSplineCompInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_B_SPLINE_COMP_INTERPOLATOR_WRITE
}

string ABSplineCompInterpolator::asString( bool verbose ) const {
	A_B_SPLINE_COMP_INTERPOLATOR_STRING
}

void ABSplineCompInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	A_B_SPLINE_COMP_INTERPOLATOR_FIXLINKS
}

