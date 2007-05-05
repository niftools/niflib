/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTransformInterpolator.h"
#include "../../include/obj/NiTransformData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformInterpolator::TYPE("NiTransformInterpolator", &NI_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiTransformInterpolator::NiTransformInterpolator() NI_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiTransformInterpolator::~NiTransformInterpolator() {}

void NiTransformInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTransformInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTransformInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTransformInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTransformInterpolator::GetRefs() const {
	return InternalGetRefs();
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

Ref<NiTransformData> NiTransformInterpolator::GetData() const {
	return data;
}

void NiTransformInterpolator::SetData( NiTransformData * value ) {
	data = value;
}
