/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatInterpolator.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatInterpolator::TYPE("NiFloatInterpolator", &NI_FLOAT_INTERPOLATOR_PARENT::TypeConst() );

NiFloatInterpolator::NiFloatInterpolator() NI_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiFloatInterpolator::~NiFloatInterpolator() {}

void NiFloatInterpolator::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiFloatInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiFloatInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiFloatInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatInterpolator::GetType() const {
	return TYPE;
};

float NiFloatInterpolator::GetFloatValue() const {
	return floatValue;
}

void NiFloatInterpolator::SetFloatValue( float value ) {
	floatValue = value;
}

Ref<NiFloatData > NiFloatInterpolator::GetData() const {
	return data;
}

void NiFloatInterpolator::SetData( Ref<NiFloatData > value ) {
	data = value;
}

