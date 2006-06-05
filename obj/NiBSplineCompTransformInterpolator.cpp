/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBSplineCompTransformInterpolator.h"
#include "NiBSplineData.h"
#include "NiBSplineBasisData.h"

//Definition of TYPE constant
const Type NiBSplineCompTransformInterpolator::TYPE("NiBSplineCompTransformInterpolator", &NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator() NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompTransformInterpolator::~NiBSplineCompTransformInterpolator() {}

void NiBSplineCompTransformInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_READ
}

void NiBSplineCompTransformInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_WRITE
}

string NiBSplineCompTransformInterpolator::asString( bool verbose ) const {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_STRING
}

void NiBSplineCompTransformInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBSplineCompTransformInterpolator::GetRefs() const {
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_GETREFS
}

const Type & NiBSplineCompTransformInterpolator::GetType() const {
	return TYPE;
};

