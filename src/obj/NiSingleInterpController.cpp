/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiSingleInterpController.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSingleInterpController::TYPE("NiSingleInterpController", &NI_SINGLE_INTERP_CONTROLLER_PARENT::TYPE );

NiSingleInterpController::NiSingleInterpController() NI_SINGLE_INTERP_CONTROLLER_CONSTRUCT {}

NiSingleInterpController::~NiSingleInterpController() {}

void NiSingleInterpController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSingleInterpController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSingleInterpController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSingleInterpController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiSingleInterpController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSingleInterpController::GetType() const {
	return TYPE;
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
		global_object_map["NiSingleInterpController"] = NiSingleInterpController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiSingleInterpController::Create() {
	return new NiSingleInterpController;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiInterpolator > NiSingleInterpController::GetInterpolator() const {
	return interpolator;
}

void NiSingleInterpController::SetInterpolator( NiInterpolator * value ) {
	interpolator = value;
}

//--END CUSTOM CODE--//