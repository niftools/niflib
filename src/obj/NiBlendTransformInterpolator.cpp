/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendTransformInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendTransformInterpolator::TYPE("NiBlendTransformInterpolator", &NI_BLEND_TRANSFORM_INTERPOLATOR_PARENT::TypeConst() );

NiBlendTransformInterpolator::NiBlendTransformInterpolator() NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiBlendTransformInterpolator::~NiBlendTransformInterpolator() {}

void NiBlendTransformInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBlendTransformInterpolator::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBlendTransformInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendTransformInterpolator::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBlendTransformInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendTransformInterpolator::GetType() const {
	return TYPE;
};

