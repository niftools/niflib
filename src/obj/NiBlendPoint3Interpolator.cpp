/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendPoint3Interpolator::TYPE("NiBlendPoint3Interpolator", &NI_BLEND_POINT3_INTERPOLATOR_PARENT::TypeConst() );

NiBlendPoint3Interpolator::NiBlendPoint3Interpolator() NI_BLEND_POINT3_INTERPOLATOR_CONSTRUCT {}

NiBlendPoint3Interpolator::~NiBlendPoint3Interpolator() {}

void NiBlendPoint3Interpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBlendPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBlendPoint3Interpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

