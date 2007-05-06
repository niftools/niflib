/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiMeshPSysData.h"
#include "../../include/obj/NiPSysModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NI_MESH_P_SYS_DATA_PARENT::TYPE );

NiMeshPSysData::NiMeshPSysData() NI_MESH_P_SYS_DATA_CONSTRUCT {}

NiMeshPSysData::~NiMeshPSysData() {}

void NiMeshPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiMeshPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiMeshPSysData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMeshPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMeshPSysData::GetType() const {
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
		global_object_map["NiMeshPSysData"] = NiMeshPSysData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiMeshPSysData::Create() {
	return new NiMeshPSysData;
}
