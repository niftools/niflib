/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendBoolInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendBoolInterpolator::TYPE("NiBlendBoolInterpolator", &NI_BLEND_BOOL_INTERPOLATOR_PARENT::TypeConst() );

NiBlendBoolInterpolator::NiBlendBoolInterpolator() NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBlendBoolInterpolator::~NiBlendBoolInterpolator() {}

void NiBlendBoolInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBlendBoolInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBlendBoolInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendBoolInterpolator::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

