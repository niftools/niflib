/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStencilProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStencilProperty::TYPE("NiStencilProperty", &NI_STENCIL_PROPERTY_PARENT::TypeConst() );

NiStencilProperty::NiStencilProperty() NI_STENCIL_PROPERTY_CONSTRUCT {}

NiStencilProperty::~NiStencilProperty() {}

void NiStencilProperty::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiStencilProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiStencilProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStencilProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

bool NiStencilProperty::GetStencilEnabled() const {
   return (stencilEnabled != 0);
}

void NiStencilProperty::SetStencilEnabled(bool value) {
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

FaceDrawMode NiStencilProperty::GetDrawMode() const {
   return drawMode;
}

void NiStencilProperty::SetDrawMode(FaceDrawMode value) {
   drawMode = value;
}
