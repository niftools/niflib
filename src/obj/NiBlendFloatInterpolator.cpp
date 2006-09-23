/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendFloatInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendFloatInterpolator::TYPE("NiBlendFloatInterpolator", &NI_BLEND_FLOAT_INTERPOLATOR_PARENT::TypeConst() );

NiBlendFloatInterpolator::NiBlendFloatInterpolator() NI_BLEND_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiBlendFloatInterpolator::~NiBlendFloatInterpolator() {}

void NiBlendFloatInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBlendFloatInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBlendFloatInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendFloatInterpolator::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBlendFloatInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendFloatInterpolator::GetType() const {
	return TYPE;
};

float NiBlendFloatInterpolator::GetFloatValue() const {
	return floatValue;
}

void NiBlendFloatInterpolator::SetFloatValue( float value ) {
	floatValue = value;
}

