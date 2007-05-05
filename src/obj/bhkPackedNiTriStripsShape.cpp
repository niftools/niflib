/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkPackedNiTriStripsShape.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPackedNiTriStripsShape::TYPE("bhkPackedNiTriStripsShape", &BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT::TYPE );

bhkPackedNiTriStripsShape::bhkPackedNiTriStripsShape() BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkPackedNiTriStripsShape::~bhkPackedNiTriStripsShape() {}

void bhkPackedNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkPackedNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkPackedNiTriStripsShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkPackedNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkPackedNiTriStripsShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkPackedNiTriStripsShape::GetType() const {
	return TYPE;
};

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["bhkPackedNiTriStripsShape"] = bhkPackedNiTriStripsShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkPackedNiTriStripsShape::Create() {
	return new bhkPackedNiTriStripsShape;
}
