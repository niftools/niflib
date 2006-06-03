/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBSplineCompTransformInterpolator.h"

//Definition of TYPE constant
const Type NiBSplineCompTransformInterpolator::TYPE("NiBSplineCompTransformInterpolator", &NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator() NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompTransformInterpolator::~NiBSplineCompTransformInterpolator() {}

void NiBSplineCompTransformInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_READ
}

void NiBSplineCompTransformInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_WRITE
}

string NiBSplineCompTransformInterpolator::asString( bool verbose ) const {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_STRING
}

void NiBSplineCompTransformInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_FIXLINKS
}

const Type & NiBSplineCompTransformInterpolator::GetType() const {
	return TYPE;
};

