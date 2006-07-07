/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBSplineInterpolator.h"
#include "NiBSplineData.h"
#include "NiBSplineBasisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineInterpolator::TYPE("NiBSplineInterpolator", &NI_B_SPLINE_INTERPOLATOR_PARENT::TypeConst() );

NiBSplineInterpolator::NiBSplineInterpolator() NI_B_SPLINE_INTERPOLATOR_CONSTRUCT {}

NiBSplineInterpolator::~NiBSplineInterpolator() {}

void NiBSplineInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_SPLINE_INTERPOLATOR_READ
}

void NiBSplineInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_B_SPLINE_INTERPOLATOR_WRITE
}

string NiBSplineInterpolator::asString( bool verbose ) const {
	NI_B_SPLINE_INTERPOLATOR_STRING
}

void NiBSplineInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_SPLINE_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBSplineInterpolator::GetRefs() const {
	NI_B_SPLINE_INTERPOLATOR_GETREFS
}

const Type & NiBSplineInterpolator::GetType() const {
	return TYPE;
};

float NiBSplineInterpolator::GetStartTime() const {
	return startTime;
}

void NiBSplineInterpolator::SetStartTime( float value ) {
	startTime = value;
}

float NiBSplineInterpolator::GetStopTime() const {
	return stopTime;
}

void NiBSplineInterpolator::SetStopTime( float value ) {
	stopTime = value;
}

Ref<NiBSplineData > NiBSplineInterpolator::GetSplineData() const {
	return splineData;
}

void NiBSplineInterpolator::SetSplineData( Ref<NiBSplineData > value ) {
	splineData = value;
}

Ref<NiBSplineBasisData > NiBSplineInterpolator::GetBasisData() const {
	return basisData;
}

void NiBSplineInterpolator::SetBasisData( Ref<NiBSplineBasisData > value ) {
	basisData = value;
}