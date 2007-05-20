/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiSpecularProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSpecularProperty::TYPE("NiSpecularProperty", &NI_SPECULAR_PROPERTY_PARENT::TYPE );

NiSpecularProperty::NiSpecularProperty() NI_SPECULAR_PROPERTY_CONSTRUCT {}

NiSpecularProperty::~NiSpecularProperty() {}

void NiSpecularProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSpecularProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSpecularProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSpecularProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiSpecularProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSpecularProperty::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

unsigned short NiSpecularProperty::GetFlags() const {
   return flags;
}

void NiSpecularProperty::SetFlags( unsigned short n ) {
   flags = n;
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
		global_object_map["NiSpecularProperty"] = NiSpecularProperty::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiSpecularProperty::Create() {
	return new NiSpecularProperty;
}
