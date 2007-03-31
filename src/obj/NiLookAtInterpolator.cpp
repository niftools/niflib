/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLookAtInterpolator.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiPoint3Interpolator.h"
#include "../../include/obj/NiFloatInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLookAtInterpolator::TYPE("NiLookAtInterpolator", &NI_LOOK_AT_INTERPOLATOR_PARENT::TypeConst() );

NiLookAtInterpolator::NiLookAtInterpolator() NI_LOOK_AT_INTERPOLATOR_CONSTRUCT {}

NiLookAtInterpolator::~NiLookAtInterpolator() {}

void NiLookAtInterpolator::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiLookAtInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiLookAtInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLookAtInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiLookAtInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLookAtInterpolator::GetType() const {
	return TYPE;
};

Ref<NiNode > NiLookAtInterpolator::GetLookAt() const {
	return lookAt;
}

void NiLookAtInterpolator::SetLookAt( Ref<NiNode > value ) {
	lookAt = value;
}

Vector3 NiLookAtInterpolator::GetTranslation() const {
	return translation;
}

void NiLookAtInterpolator::SetTranslation( Vector3 value ) {
	translation = value;
}

Quaternion NiLookAtInterpolator::GetRotation() const {
	return rotation;
}

void NiLookAtInterpolator::SetRotation( Quaternion value ) {
	rotation = value;
}

float NiLookAtInterpolator::GetScale() const {
	return scale;
}

void NiLookAtInterpolator::SetScale( float value ) {
	scale = value;
}

const Type & NiLookAtInterpolator::TypeConst() {
	return TYPE;
}
