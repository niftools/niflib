/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBSplineCompFloatInterpolator.h"

//Definition of TYPE constant
const Type NiBSplineCompFloatInterpolator::TYPE("NiBSplineCompFloatInterpolator", &NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENT::TYPE );

NiBSplineCompFloatInterpolator::NiBSplineCompFloatInterpolator() NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompFloatInterpolator::~NiBSplineCompFloatInterpolator() {}

void NiBSplineCompFloatInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_READ
}

void NiBSplineCompFloatInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_WRITE
}

string NiBSplineCompFloatInterpolator::asString( bool verbose ) const {
	NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_STRING
}

void NiBSplineCompFloatInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBSplineCompFloatInterpolator::GetRefs() const {
	NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_GETREFS
}

const Type & NiBSplineCompFloatInterpolator::GetType() const {
	return TYPE;
};

