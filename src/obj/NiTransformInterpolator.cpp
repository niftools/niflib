/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTransformInterpolator.h"
#include "../../include/obj/NiTransformData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformInterpolator::TYPE("NiTransformInterpolator", &NI_TRANSFORM_INTERPOLATOR_PARENT::TypeConst() );

NiTransformInterpolator::NiTransformInterpolator() NI_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiTransformInterpolator::~NiTransformInterpolator() {}

void NiTransformInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRANSFORM_INTERPOLATOR_READ
}

void NiTransformInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRANSFORM_INTERPOLATOR_WRITE
}

string NiTransformInterpolator::asString( bool verbose ) const {
	NI_TRANSFORM_INTERPOLATOR_STRING
}

void NiTransformInterpolator::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRANSFORM_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiTransformInterpolator::GetRefs() const {
	NI_TRANSFORM_INTERPOLATOR_GETREFS
}

const Type & NiTransformInterpolator::GetType() const {
	return TYPE;
};

Vector3 NiTransformInterpolator::GetTranslation() const {
	return translation;
}

void NiTransformInterpolator::SetTranslation( Vector3 value ) {
	translation = value;
}

Quaternion NiTransformInterpolator::GetRotation() const {
	return rotation;
}

void NiTransformInterpolator::SetRotation( Quaternion value ) {
	rotation = value;
}

float NiTransformInterpolator::GetScale() const {
	return scale;
}

void NiTransformInterpolator::SetScale( float value ) {
	scale = value;
}

Ref<NiTransformData > NiTransformInterpolator::GetData() const {
	return data;
}

void NiTransformInterpolator::SetData( Ref<NiTransformData > value ) {
	data = value;
}

