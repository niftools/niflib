/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiPSysPlanarCollider.h"
#include "../../include/obj/NiPSysSpawnModifier.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysPlanarCollider::TYPE("NiPSysPlanarCollider", &NI_P_SYS_PLANAR_COLLIDER_PARENT::TYPE );

NiPSysPlanarCollider::NiPSysPlanarCollider() NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT {}

NiPSysPlanarCollider::~NiPSysPlanarCollider() {}

void NiPSysPlanarCollider::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysPlanarCollider::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysPlanarCollider::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysPlanarCollider::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysPlanarCollider::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysPlanarCollider::GetType() const {
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
		global_object_map["NiPSysPlanarCollider"] = NiPSysPlanarCollider::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPSysPlanarCollider::Create() {
	return new NiPSysPlanarCollider;
}
