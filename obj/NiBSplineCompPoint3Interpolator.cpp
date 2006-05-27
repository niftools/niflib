/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBSplineCompPoint3Interpolator.h"

//Definition of TYPE constant
const Type NiBSplineCompPoint3Interpolator::TYPE("NiBSplineCompPoint3Interpolator", &NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT::TYPE );

NiBSplineCompPoint3Interpolator::NiBSplineCompPoint3Interpolator() NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompPoint3Interpolator::~NiBSplineCompPoint3Interpolator() {}

void NiBSplineCompPoint3Interpolator::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_READ
}

void NiBSplineCompPoint3Interpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_WRITE
}

string NiBSplineCompPoint3Interpolator::asString( bool verbose ) const {
	NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_STRING
}

void NiBSplineCompPoint3Interpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_FIXLINKS
}

