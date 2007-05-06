/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/bhkSphereShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSphereShape::TYPE("bhkSphereShape", &BHK_SPHERE_SHAPE_PARENT::TYPE );

bhkSphereShape::bhkSphereShape() BHK_SPHERE_SHAPE_CONSTRUCT {}

bhkSphereShape::~bhkSphereShape() {}

void bhkSphereShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkSphereShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkSphereShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSphereShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkSphereShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSphereShape::GetType() const {
	return TYPE;
};

float bhkSphereShape::GetRadius() const {
	return radius;
}

void bhkSphereShape::SetRadius( float value ) {
	radius = value;
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
		global_object_map["bhkSphereShape"] = bhkSphereShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkSphereShape::Create() {
	return new bhkSphereShape;
}
