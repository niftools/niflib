/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiInterpController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiInterpController::TYPE("NiInterpController", &NI_INTERP_CONTROLLER_PARENT::TYPE );

NiInterpController::NiInterpController() NI_INTERP_CONTROLLER_CONSTRUCT {}

NiInterpController::~NiInterpController() {}

void NiInterpController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiInterpController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiInterpController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiInterpController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiInterpController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiInterpController::GetType() const {
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
		global_object_map["NiInterpController"] = NiInterpController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiInterpController::Create() {
	return new NiInterpController;
}

