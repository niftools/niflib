/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendPoint3Interpolator::TYPE("NiBlendPoint3Interpolator", &NI_BLEND_POINT3_INTERPOLATOR_PARENT::TypeConst() );

NiBlendPoint3Interpolator::NiBlendPoint3Interpolator() NI_BLEND_POINT3_INTERPOLATOR_CONSTRUCT {}

NiBlendPoint3Interpolator::~NiBlendPoint3Interpolator() {}

void NiBlendPoint3Interpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBlendPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBlendPoint3Interpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBlendPoint3Interpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendPoint3Interpolator::GetType() const {
	return TYPE;
};

Vector3 NiBlendPoint3Interpolator::GetPointValue() const {
	return pointValue;
}

void NiBlendPoint3Interpolator::SetPointValue( Vector3 value ) {
	pointValue = value;
}

const Type & NiBlendPoint3Interpolator::TypeConst() {
	return TYPE;
}
