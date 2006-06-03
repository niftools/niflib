/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBlendTransformInterpolator.h"

//Definition of TYPE constant
const Type NiBlendTransformInterpolator::TYPE("NiBlendTransformInterpolator", &NI_BLEND_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiBlendTransformInterpolator::NiBlendTransformInterpolator() NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiBlendTransformInterpolator::~NiBlendTransformInterpolator() {}

void NiBlendTransformInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_BLEND_TRANSFORM_INTERPOLATOR_READ
}

void NiBlendTransformInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_BLEND_TRANSFORM_INTERPOLATOR_WRITE
}

string NiBlendTransformInterpolator::asString( bool verbose ) const {
	NI_BLEND_TRANSFORM_INTERPOLATOR_STRING
}

void NiBlendTransformInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_BLEND_TRANSFORM_INTERPOLATOR_FIXLINKS
}

const Type & NiBlendTransformInterpolator::GetType() const {
	return TYPE;
};

