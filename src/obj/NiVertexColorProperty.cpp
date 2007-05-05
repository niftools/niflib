/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVertexColorProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVertexColorProperty::TYPE("NiVertexColorProperty", &NI_VERTEX_COLOR_PROPERTY_PARENT::TYPE );

NiVertexColorProperty::NiVertexColorProperty() NI_VERTEX_COLOR_PROPERTY_CONSTRUCT {}

NiVertexColorProperty::~NiVertexColorProperty() {}

void NiVertexColorProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiVertexColorProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiVertexColorProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVertexColorProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiVertexColorProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVertexColorProperty::GetType() const {
	return TYPE;
};

unsigned short NiVertexColorProperty::GetFlags() const {
   return flags;
}

void NiVertexColorProperty::SetFlags(unsigned short value) {
   flags = value;
}

VertMode NiVertexColorProperty::GetVertexMode() const {
   return vertexMode;
}

void NiVertexColorProperty::SetVertexMode(VertMode value) {
   vertexMode = value;
}

LightMode NiVertexColorProperty::GetLightingMode() const {
   return lightingMode;
}

void NiVertexColorProperty::SetLightingMode(LightMode value) {
   lightingMode = value;
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
		global_object_map["NiVertexColorProperty"] = NiVertexColorProperty::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiVertexColorProperty::Create() {
	return new NiVertexColorProperty;
}
