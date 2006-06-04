/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiTransformInterpolator.h"
#include "obj/NiTransformData.h"

//Definition of TYPE constant
const Type NiTransformInterpolator::TYPE("NiTransformInterpolator", &NI_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiTransformInterpolator::NiTransformInterpolator() NI_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiTransformInterpolator::~NiTransformInterpolator() {}

void NiTransformInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_TRANSFORM_INTERPOLATOR_READ
}

void NiTransformInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TRANSFORM_INTERPOLATOR_WRITE
}

string NiTransformInterpolator::asString( bool verbose ) const {
	NI_TRANSFORM_INTERPOLATOR_STRING
}

void NiTransformInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_TRANSFORM_INTERPOLATOR_FIXLINKS
}

const Type & NiTransformInterpolator::GetType() const {
	return TYPE;
};

