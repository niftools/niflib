/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineCompPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineCompPoint3Interpolator::TYPE("NiBSplineCompPoint3Interpolator", &NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT::TYPE );

NiBSplineCompPoint3Interpolator::NiBSplineCompPoint3Interpolator() NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompPoint3Interpolator::~NiBSplineCompPoint3Interpolator() {}

void NiBSplineCompPoint3Interpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSplineCompPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSplineCompPoint3Interpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineCompPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSplineCompPoint3Interpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineCompPoint3Interpolator::GetType() const {
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
		global_object_map["NiBSplineCompPoint3Interpolator"] = NiBSplineCompPoint3Interpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBSplineCompPoint3Interpolator::Create() {
	return new NiBSplineCompPoint3Interpolator;
}
