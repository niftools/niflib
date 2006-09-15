/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBlendBoolInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendBoolInterpolator::TYPE("NiBlendBoolInterpolator", &NI_BLEND_BOOL_INTERPOLATOR_PARENT::TypeConst() );

NiBlendBoolInterpolator::NiBlendBoolInterpolator() NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBlendBoolInterpolator::~NiBlendBoolInterpolator() {}

void NiBlendBoolInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BLEND_BOOL_INTERPOLATOR_READ
}

void NiBlendBoolInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BLEND_BOOL_INTERPOLATOR_WRITE
}

string NiBlendBoolInterpolator::asString( bool verbose ) const {
	NI_BLEND_BOOL_INTERPOLATOR_STRING
}

void NiBlendBoolInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BLEND_BOOL_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBlendBoolInterpolator::GetRefs() const {
	NI_BLEND_BOOL_INTERPOLATOR_GETREFS
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

