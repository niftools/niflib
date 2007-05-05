/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendTransformInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendTransformInterpolator::TYPE("NiBlendTransformInterpolator", &NI_BLEND_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiBlendTransformInterpolator::NiBlendTransformInterpolator() NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiBlendTransformInterpolator::~NiBlendTransformInterpolator() {}

void NiBlendTransformInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBlendTransformInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBlendTransformInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendTransformInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBlendTransformInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendTransformInterpolator::GetType() const {
	return TYPE;
};
