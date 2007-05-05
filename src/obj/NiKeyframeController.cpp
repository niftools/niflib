/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiKeyframeController::TYPE("NiKeyframeController", &NI_KEYFRAME_CONTROLLER_PARENT::TYPE );

NiKeyframeController::NiKeyframeController() NI_KEYFRAME_CONTROLLER_CONSTRUCT {}

NiKeyframeController::~NiKeyframeController() {}

void NiKeyframeController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiKeyframeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiKeyframeController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiKeyframeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiKeyframeController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiKeyframeController::GetType() const {
	return TYPE;
};

Ref<NiKeyframeData> NiKeyframeController::GetData() const {
	return data;
}
	
void NiKeyframeController::SetData( NiKeyframeData * n ) {
	data = n;
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
		global_object_map["NiKeyframeController"] = NiKeyframeController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiKeyframeController::Create() {
	return new NiKeyframeController;
}
