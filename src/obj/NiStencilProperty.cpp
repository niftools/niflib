/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStencilProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStencilProperty::TYPE("NiStencilProperty", &NI_STENCIL_PROPERTY_PARENT::TYPE );

NiStencilProperty::NiStencilProperty() NI_STENCIL_PROPERTY_CONSTRUCT {}

NiStencilProperty::~NiStencilProperty() {}

void NiStencilProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiStencilProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiStencilProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStencilProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiStencilProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiStencilProperty::GetType() const {
	return TYPE;
};

unsigned short NiStencilProperty::GetFlags() const {
   return flags;
}

void NiStencilProperty::SetFlags(unsigned short value) {
   flags = value;
}

bool NiStencilProperty::GetStencilState() const {
   return (stencilEnabled != 0);
}

void NiStencilProperty::SetStencilState(bool value) {
   stencilEnabled = value;
}

CompareMode NiStencilProperty::GetStencilFunction() const {
   return stencilFunction;
}

void NiStencilProperty::SetStencilFunction(CompareMode value) {
   stencilFunction = value;
}

unsigned int NiStencilProperty::GetStencilRef() const {
   return stencilRef;
}

void NiStencilProperty::SetStencilRef(unsigned int value) {
   stencilRef = value;
}

unsigned int NiStencilProperty::GetStencilMask() const {
   return stencilMask;
}

void NiStencilProperty::SetStencilMask(unsigned int value) {
   stencilMask = value;
}

StencilAction NiStencilProperty::GetFailAction() const {
   return failAction;
}

void NiStencilProperty::SetFailAction(StencilAction value) {
   failAction = value;
}

StencilAction NiStencilProperty::GetZFailAction() const {
   return zFailAction;
}

void NiStencilProperty::SetZFailAction(StencilAction value) {
   zFailAction = value;
}

StencilAction NiStencilProperty::GetPassAction() const {
   return passAction;
}

void NiStencilProperty::SetPassAction(StencilAction value) {
   passAction = value;
}

FaceDrawMode NiStencilProperty::GetFaceDrawMode() const {
   return drawMode;
}

void NiStencilProperty::SetFaceDrawMode(FaceDrawMode value) {
   drawMode = value;
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
		global_object_map["NiStencilProperty"] = NiStencilProperty::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiStencilProperty::Create() {
	return new NiStencilProperty;
}
