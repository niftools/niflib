/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiUVController.h"
#include "../../include/obj/NiUVData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiUVController::TYPE("NiUVController", &NI_U_V_CONTROLLER_PARENT::TYPE );

NiUVController::NiUVController() NI_U_V_CONTROLLER_CONSTRUCT {}

NiUVController::~NiUVController() {}

void NiUVController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiUVController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiUVController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiUVController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiUVController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiUVController::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

Ref<NiUVData> NiUVController::GetData() const {
	return data;
}

void NiUVController::SetData( NiUVData * n ) {
	data = n;
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
		global_object_map["NiUVController"] = NiUVController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiUVController::Create() {
	return new NiUVController;
}
