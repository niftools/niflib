/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiPSysCollider.h"
#include "../../include/obj/NiPSysSpawnModifier.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysCollider::TYPE("NiPSysCollider", &NI_P_SYS_COLLIDER_PARENT::TYPE );

NiPSysCollider::NiPSysCollider() NI_P_SYS_COLLIDER_CONSTRUCT {}

NiPSysCollider::~NiPSysCollider() {}

void NiPSysCollider::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysCollider::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysCollider::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysCollider::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysCollider::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysCollider::GetType() const {
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
		global_object_map["NiPSysCollider"] = NiPSysCollider::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPSysCollider::Create() {
	return new NiPSysCollider;
}

