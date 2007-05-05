/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFogProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFogProperty::TYPE("NiFogProperty", &NI_FOG_PROPERTY_PARENT::TYPE );

NiFogProperty::NiFogProperty() NI_FOG_PROPERTY_CONSTRUCT {}

NiFogProperty::~NiFogProperty() {}

void NiFogProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiFogProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiFogProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFogProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiFogProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFogProperty::GetType() const {
	return TYPE;
};


unsigned short NiFogProperty::GetFlags() const {
   return flags;
}

void NiFogProperty::SetFlags( unsigned short n ) {
   flags = n;
}

float NiFogProperty::GetFogDepth() const {
   return fogDepth;
}

void NiFogProperty::SetFogDepth(float value) {
   fogDepth = value;
}

Color3 NiFogProperty::GetFogColor() const {
   return fogColor;
}

void NiFogProperty::SetFogColor(Color3 value) {
   fogColor = value;
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
		global_object_map["NiFogProperty"] = NiFogProperty::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiFogProperty::Create() {
	return new NiFogProperty;
}
