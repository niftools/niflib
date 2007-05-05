/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiCamera.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCamera::TYPE("NiCamera", &NI_CAMERA_PARENT::TYPE );

NiCamera::NiCamera() NI_CAMERA_CONSTRUCT {}

NiCamera::~NiCamera() {}

void NiCamera::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiCamera::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiCamera::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiCamera::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiCamera::GetRefs() const {
	return InternalGetRefs();
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

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiCamera"] = NiCamera::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiCamera::Create() {
	return new NiCamera;
}
