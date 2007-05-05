/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSParentVelocityModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSParentVelocityModifier::TYPE("BSParentVelocityModifier", &B_S_PARENT_VELOCITY_MODIFIER_PARENT::TYPE );

BSParentVelocityModifier::BSParentVelocityModifier() B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT {}

BSParentVelocityModifier::~BSParentVelocityModifier() {}

void BSParentVelocityModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void BSParentVelocityModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string BSParentVelocityModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSParentVelocityModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> BSParentVelocityModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSParentVelocityModifier::GetType() const {
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
		global_object_map["BSParentVelocityModifier"] = BSParentVelocityModifier::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * BSParentVelocityModifier::Create() {
	return new BSParentVelocityModifier;
}
