/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkBoxShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBoxShape::TYPE("bhkBoxShape", &BHK_BOX_SHAPE_PARENT::TYPE );

bhkBoxShape::bhkBoxShape() BHK_BOX_SHAPE_CONSTRUCT {}

bhkBoxShape::~bhkBoxShape() {}

void bhkBoxShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkBoxShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkBoxShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkBoxShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkBoxShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkBoxShape::GetType() const {
	return TYPE;
};

Vector3 bhkBoxShape::GetDimensions() const {
	return dimensions;
}

void bhkBoxShape::SetDimensions(const Vector3 &value) {
	dimensions = value;
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
		global_object_map["bhkBoxShape"] = bhkBoxShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkBoxShape::Create() {
	return new bhkBoxShape;
}
