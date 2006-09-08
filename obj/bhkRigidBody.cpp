/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkRigidBody.h"
#include "../gen/QuaternionXYZW.h"
#include "AbhkConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBody::TYPE("bhkRigidBody", &BHK_RIGID_BODY_PARENT::TypeConst() );

bhkRigidBody::bhkRigidBody() BHK_RIGID_BODY_CONSTRUCT {}

bhkRigidBody::~bhkRigidBody() {}

void bhkRigidBody::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_RIGID_BODY_READ
}

void bhkRigidBody::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_RIGID_BODY_WRITE
}

string bhkRigidBody::asString( bool verbose ) const {
	BHK_RIGID_BODY_STRING
}

void bhkRigidBody::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_RIGID_BODY_FIXLINKS
}

list<NiObjectRef> bhkRigidBody::GetRefs() const {
	BHK_RIGID_BODY_GETREFS
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

array<float,12>  bhkRigidBody::GetTransform() const {
	return transform;
}

void bhkRigidBody::SetTransform( const array<float,12>&  value ) {
	transform = value;
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

byte bhkRigidBody::GetMotionSystem() const {
	return motionSystem;
}

void bhkRigidBody::SetMotionSystem( byte value ) {
	motionSystem = value;
}

MotionQuality bhkRigidBody::GetQualityType() const {
	return qualityType;
}

void bhkRigidBody::SetQualityType( MotionQuality value ) {
	qualityType = value;
}
