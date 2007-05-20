/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiPoint3InterpController.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPoint3InterpController::TYPE("NiPoint3InterpController", &NI_POINT3_INTERP_CONTROLLER_PARENT::TYPE );

NiPoint3InterpController::NiPoint3InterpController() NI_POINT3_INTERP_CONTROLLER_CONSTRUCT {}

NiPoint3InterpController::~NiPoint3InterpController() {}

void NiPoint3InterpController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPoint3InterpController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPoint3InterpController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPoint3InterpController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPoint3InterpController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPoint3InterpController::GetType() const {
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
		global_object_map["NiPoint3InterpController"] = NiPoint3InterpController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPoint3InterpController::Create() {
	return new NiPoint3InterpController;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiPosData > NiPoint3InterpController::GetData() const {
	return data;
}

void NiPoint3InterpController::SetData( NiPosData * value ) {
	data = value;
}

//--END CUSTOM CODE--//