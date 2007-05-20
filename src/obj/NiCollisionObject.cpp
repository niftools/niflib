/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiCollisionObject.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionObject::TYPE("NiCollisionObject", &NI_COLLISION_OBJECT_PARENT::TYPE );

NiCollisionObject::NiCollisionObject() NI_COLLISION_OBJECT_CONSTRUCT {}

NiCollisionObject::~NiCollisionObject() {}

void NiCollisionObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiCollisionObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiCollisionObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiCollisionObject::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

Ref<NiAVObject> NiCollisionObject::GetTarget() const {
	return target;
}

void NiCollisionObject::SetTarget( NiAVObject * value ) {
	target = value;
}

Ref<NiObject > NiCollisionObject::GetBody() const {
	return body;
}

void NiCollisionObject::SetBody( NiObject * value ) {
	body = value;
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
		global_object_map["NiCollisionObject"] = NiCollisionObject::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiCollisionObject::Create() {
	return new NiCollisionObject;
}
