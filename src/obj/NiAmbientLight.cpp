/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiAmbientLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAmbientLight::TYPE("NiAmbientLight", &NI_AMBIENT_LIGHT_PARENT::TYPE );

NiAmbientLight::NiAmbientLight() NI_AMBIENT_LIGHT_CONSTRUCT {}

NiAmbientLight::~NiAmbientLight() {}

void NiAmbientLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAmbientLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAmbientLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAmbientLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAmbientLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAmbientLight::GetType() const {
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
		global_object_map["NiAmbientLight"] = NiAmbientLight::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiAmbientLight::Create() {
	return new NiAmbientLight;
}
