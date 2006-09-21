/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkCapsuleShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCapsuleShape::TYPE("bhkCapsuleShape", &BHK_CAPSULE_SHAPE_PARENT::TypeConst() );

bhkCapsuleShape::bhkCapsuleShape() BHK_CAPSULE_SHAPE_CONSTRUCT {}

bhkCapsuleShape::~bhkCapsuleShape() {}

void bhkCapsuleShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_CAPSULE_SHAPE_READ
}

void bhkCapsuleShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_CAPSULE_SHAPE_WRITE
}

string bhkCapsuleShape::asString( bool verbose ) const {
	BHK_CAPSULE_SHAPE_STRING
}

void bhkCapsuleShape::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_CAPSULE_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkCapsuleShape::GetRefs() const {
	BHK_CAPSULE_SHAPE_GETREFS
}

const Type & bhkCapsuleShape::GetType() const {
	return TYPE;
};

float bhkCapsuleShape::GetRadius() const {
	return radius;
}

void bhkCapsuleShape::SetRadius( float value ) {
	radius = value;
}

Vector3 bhkCapsuleShape::GetFirstPoint() const {
	return firstPoint;
}

void bhkCapsuleShape::SetFirstPoint( const Vector3 & value ) {
	firstPoint = value;
}

float bhkCapsuleShape::GetRadius1() const {
	return radius1;
}

void bhkCapsuleShape::SetRadius1( float value ) {
	radius1 = value;
}

Vector3 bhkCapsuleShape::GetSecondPoint() const {
	return secondPoint;
}

void bhkCapsuleShape::SetSecondPoint( const Vector3 & value ) {
	secondPoint = value;
}

float bhkCapsuleShape::GetRadius2() const {
	return radius2;
}

void bhkCapsuleShape::SetRadius2( float value ) {
	radius2 = value;
}

