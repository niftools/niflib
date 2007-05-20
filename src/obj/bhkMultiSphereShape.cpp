/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/bhkMultiSphereShape.h"
#include "../../include/gen/Sphere.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMultiSphereShape::TYPE("bhkMultiSphereShape", &BHK_MULTI_SPHERE_SHAPE_PARENT::TYPE );

bhkMultiSphereShape::bhkMultiSphereShape() BHK_MULTI_SPHERE_SHAPE_CONSTRUCT {}

bhkMultiSphereShape::~bhkMultiSphereShape() {}

void bhkMultiSphereShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkMultiSphereShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkMultiSphereShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkMultiSphereShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkMultiSphereShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkMultiSphereShape::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

vector<Sphere > bhkMultiSphereShape::GetSpheres() const {
	return spheres;
}

void bhkMultiSphereShape::SetSpheres( const vector<Sphere >& value ) {
	spheres = value;
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
		global_object_map["bhkMultiSphereShape"] = bhkMultiSphereShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkMultiSphereShape::Create() {
	return new bhkMultiSphereShape;
}
