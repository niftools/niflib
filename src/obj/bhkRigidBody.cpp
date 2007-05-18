/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/bhkRigidBody.h"
#include "../../include/gen/QuaternionXYZW.h"
#include "../../include/obj/bhkConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBody::TYPE("bhkRigidBody", &BHK_RIGID_BODY_PARENT::TYPE );

bhkRigidBody::bhkRigidBody() BHK_RIGID_BODY_CONSTRUCT {}

bhkRigidBody::~bhkRigidBody() {}

void bhkRigidBody::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkRigidBody::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkRigidBody::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRigidBody::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkRigidBody::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRigidBody::GetType() const {
	return TYPE;
};

OblivionLayer bhkRigidBody::GetLayerCopy() const {
	return layerCopy;
}

void bhkRigidBody::SetLayerCopy( OblivionLayer value ) {
	layerCopy = value;
}

Vector3 bhkRigidBody::GetTranslation() const {
	return translation;
}

void bhkRigidBody::SetTranslation( const Vector3 & value ) {
	translation = value;
}

QuaternionXYZW bhkRigidBody::GetRotation() const {
	return rotation;
}

void bhkRigidBody::SetRotation( const QuaternionXYZW & value ) {
	rotation = value;
}

Vector3 bhkRigidBody::GetLinearVelocity() const {
	return linearVelocity;
}

void bhkRigidBody::SetLinearVelocity( const Vector3 & value ) {
	linearVelocity = value;
}

Vector3 bhkRigidBody::GetAngularVelocity() const {
	return angularVelocity;
}

void bhkRigidBody::SetAngularVelocity( const Vector3 & value ) {
	angularVelocity = value;
}

array<12,float>  bhkRigidBody::GetInertia() const {
	return inertia;
}

void bhkRigidBody::SetInertia( const array<12,float>&  value ) {
	inertia = value;
}

Vector3 bhkRigidBody::GetCenter() const {
	return center;
}

void bhkRigidBody::SetCenter( const Vector3 & value ) {
	center = value;
}

float bhkRigidBody::GetMass() const {
	return mass;
}

void bhkRigidBody::SetMass( float value ) {
	mass = value;
}

float bhkRigidBody::GetLinearDamping() const {
	return linearDamping;
}

void bhkRigidBody::SetLinearDamping( float value ) {
	linearDamping = value;
}

float bhkRigidBody::GetAngularDamping() const {
	return angularDamping;
}

void bhkRigidBody::SetAngularDamping( float value ) {
	angularDamping = value;
}

float bhkRigidBody::GetFriction() const {
	return friction;
}

void bhkRigidBody::SetFriction( float value ) {
	friction = value;
}

float bhkRigidBody::GetRestitution() const {
	return restitution;
}

void bhkRigidBody::SetRestitution( float value ) {
	restitution = value;
}

float bhkRigidBody::GetMaxLinearVelocity() const {
	return maxLinearVelocity;
}

void bhkRigidBody::SetMaxLinearVelocity( float value ) {
	maxLinearVelocity = value;
}

float bhkRigidBody::GetMaxAngularVelocity() const {
	return maxAngularVelocity;
}

void bhkRigidBody::SetMaxAngularVelocity( float value ) {
	maxAngularVelocity = value;
}

float bhkRigidBody::GetPenetrationDepth() const {
	return penetrationDepth;
}

void bhkRigidBody::SetPenetrationDepth( float value ) {
	penetrationDepth = value;
}

MotionSystem bhkRigidBody::GetMotionSystem() const {
	return motionSystem;
}

void bhkRigidBody::SetMotionSystem( MotionSystem value ) {
	motionSystem = value;
}

MotionQuality bhkRigidBody::GetQualityType() const {
	return qualityType;
}

void bhkRigidBody::SetQualityType( MotionQuality value ) {
	qualityType = value;
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
		global_object_map["bhkRigidBody"] = bhkRigidBody::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkRigidBody::Create() {
	return new bhkRigidBody;
}
