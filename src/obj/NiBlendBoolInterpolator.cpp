/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendBoolInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendBoolInterpolator::TYPE("NiBlendBoolInterpolator", &NI_BLEND_BOOL_INTERPOLATOR_PARENT::TypeConst() );

NiBlendBoolInterpolator::NiBlendBoolInterpolator() NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBlendBoolInterpolator::~NiBlendBoolInterpolator() {}

void NiBlendBoolInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBlendBoolInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBlendBoolInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendBoolInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBlendBoolInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendBoolInterpolator::GetType() const {
	return TYPE;
};

byte NiBlendBoolInterpolator::GetBoolValue() const {
	return boolValue;
}

void NiBlendBoolInterpolator::SetBoolValue( byte value ) {
	boolValue = value;
}

const Type & NiBlendBoolInterpolator::TypeConst() {
	return TYPE;
}
