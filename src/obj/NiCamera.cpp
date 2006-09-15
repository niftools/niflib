/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiCamera.h"
#include "NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCamera::TYPE("NiCamera", &NI_CAMERA_PARENT::TypeConst() );

NiCamera::NiCamera() NI_CAMERA_CONSTRUCT {}

NiCamera::~NiCamera() {}

void NiCamera::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CAMERA_READ
}

void NiCamera::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_CAMERA_WRITE
}

string NiCamera::asString( bool verbose ) const {
	NI_CAMERA_STRING
}

void NiCamera::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CAMERA_FIXLINKS
}

list<NiObjectRef> NiCamera::GetRefs() const {
	NI_CAMERA_GETREFS
}

const Type & NiCamera::GetType() const {
	return TYPE;
};

float NiCamera::GetFrustumLeft() const {
	return frustumLeft;
}

void NiCamera::SetFrustumLeft( float value ) {
	frustumLeft = value;
}

float NiCamera::GetFrustumRight() const {
	return frustumRight;
}

void NiCamera::SetFrustumRight( float value ) {
	frustumRight = value;
}

float NiCamera::GetFrustumTop() const {
	return frustumTop;
}

void NiCamera::SetFrustumTop( float value ) {
	frustumTop = value;
}

float NiCamera::GetFrustumBottom() const {
	return frustumBottom;
}

void NiCamera::SetFrustumBottom( float value ) {
	frustumBottom = value;
}

float NiCamera::GetFrustumNear() const {
	return frustumNear;
}

void NiCamera::SetFrustumNear( float value ) {
	frustumNear = value;
}

float NiCamera::GetFrustumFar() const {
	return frustumFar;
}

void NiCamera::SetFrustumFar( float value ) {
	frustumFar = value;
}

bool NiCamera::GetUseOrthographicProjection() const {
	return useOrthographicProjection;
}

void NiCamera::SetUseOrthographicProjection( bool value ) {
	useOrthographicProjection = value;
}

float NiCamera::GetViewportLeft() const {
	return viewportLeft;
}

void NiCamera::SetViewportLeft( float value ) {
	viewportLeft = value;
}

float NiCamera::GetViewportRight() const {
	return viewportRight;
}

void NiCamera::SetViewportRight( float value ) {
	viewportRight = value;
}

float NiCamera::GetViewportTop() const {
	return viewportTop;
}

void NiCamera::SetViewportTop( float value ) {
	viewportTop = value;
}

float NiCamera::GetViewportBottom() const {
	return viewportBottom;
}

void NiCamera::SetViewportBottom( float value ) {
	viewportBottom = value;
}

float NiCamera::GetLodAdjust() const {
	return lodAdjust;
}

void NiCamera::SetLodAdjust( float value ) {
	lodAdjust = value;
}

