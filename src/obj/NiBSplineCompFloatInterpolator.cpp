/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineCompFloatInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineCompFloatInterpolator::TYPE("NiBSplineCompFloatInterpolator", &NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENT::TypeConst() );

NiBSplineCompFloatInterpolator::NiBSplineCompFloatInterpolator() NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompFloatInterpolator::~NiBSplineCompFloatInterpolator() {}

void NiBSplineCompFloatInterpolator::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBSplineCompFloatInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBSplineCompFloatInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineCompFloatInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBSplineCompFloatInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineCompFloatInterpolator::GetType() const {
	return TYPE;
};

