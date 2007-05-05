/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiZBufferProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiZBufferProperty::TYPE("NiZBufferProperty", &NI_Z_BUFFER_PROPERTY_PARENT::TYPE );

NiZBufferProperty::NiZBufferProperty() NI_Z_BUFFER_PROPERTY_CONSTRUCT {}

NiZBufferProperty::~NiZBufferProperty() {}

void NiZBufferProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiZBufferProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiZBufferProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiZBufferProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiZBufferProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiZBufferProperty::GetType() const {
	return TYPE;
};

unsigned short NiZBufferProperty::GetFlags() const {
   return flags;
}

void NiZBufferProperty::SetFlags(unsigned short value) {
   flags = value;
}

CompareMode NiZBufferProperty::GetDepthFunction() const {
   return function;
}

void NiZBufferProperty::SetDepthFunction(CompareMode value) {
   function = value;
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
		global_object_map["NiZBufferProperty"] = NiZBufferProperty::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiZBufferProperty::Create() {
	return new NiZBufferProperty;
}
