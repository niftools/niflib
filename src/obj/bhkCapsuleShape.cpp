/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/bhkCapsuleShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCapsuleShape::TYPE("bhkCapsuleShape", &BHK_CAPSULE_SHAPE_PARENT::TYPE );

bhkCapsuleShape::bhkCapsuleShape() BHK_CAPSULE_SHAPE_CONSTRUCT {}

bhkCapsuleShape::~bhkCapsuleShape() {}

void bhkCapsuleShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkCapsuleShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkCapsuleShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkCapsuleShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkCapsuleShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkCapsuleShape::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

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

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["bhkCapsuleShape"] = bhkCapsuleShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkCapsuleShape::Create() {
	return new bhkCapsuleShape;
}
