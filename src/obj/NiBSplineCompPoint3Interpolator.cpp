/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineCompPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineCompPoint3Interpolator::TYPE("NiBSplineCompPoint3Interpolator", &NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT::TypeConst() );

NiBSplineCompPoint3Interpolator::NiBSplineCompPoint3Interpolator() NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompPoint3Interpolator::~NiBSplineCompPoint3Interpolator() {}

void NiBSplineCompPoint3Interpolator::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBSplineCompPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBSplineCompPoint3Interpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineCompPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBSplineCompPoint3Interpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineCompPoint3Interpolator::GetType() const {
	return TYPE;
};
