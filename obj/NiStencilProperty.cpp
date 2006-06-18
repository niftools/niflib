/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiStencilProperty.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiStencilProperty::TYPE("NiStencilProperty", &NI_STENCIL_PROPERTY_PARENT::TypeConst() );

NiStencilProperty::NiStencilProperty() NI_STENCIL_PROPERTY_CONSTRUCT {}

NiStencilProperty::~NiStencilProperty() {}

void NiStencilProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STENCIL_PROPERTY_READ
}

void NiStencilProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_STENCIL_PROPERTY_WRITE
}

string NiStencilProperty::asString( bool verbose ) const {
	NI_STENCIL_PROPERTY_STRING
}

void NiStencilProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_STENCIL_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiStencilProperty::GetRefs() const {
	NI_STENCIL_PROPERTY_GETREFS
}

const Type & NiStencilProperty::GetType() const {
	return TYPE;
};

ushort NiStencilProperty::GetFlags() const {
   return flags;
}

void NiStencilProperty::SetFlags(ushort value) {
   flags = value;
}

bool NiStencilProperty::GetStencilEnabled() const {
   return stencilEnabled;
}

void NiStencilProperty::SetStencilEnabled(bool value) {
   stencilEnabled = value;
}

uint NiStencilProperty::GetStencilFunction() const {
   return stencilFunction;
}

void NiStencilProperty::SetStencilFunction(uint value) {
   stencilFunction = value;
}

uint NiStencilProperty::GetStencilRef() const {
   return stencilRef;
}

void NiStencilProperty::SetStencilRef(uint value) {
   stencilRef = value;
}

uint NiStencilProperty::GetStencilMask() const {
   return stencilMask;
}

void NiStencilProperty::SetStencilMask(uint value) {
   stencilMask = value;
}

uint NiStencilProperty::GetFailAction() const {
   return failAction;
}

void NiStencilProperty::SetFailAction(uint value) {
   failAction = value;
}

uint NiStencilProperty::GetZFailAction() const {
   return zFailAction;
}

void NiStencilProperty::SetZFailAction(uint value) {
   zFailAction = value;
}

uint NiStencilProperty::GetPassAction() const {
   return passAction;
}

void NiStencilProperty::SetPassAction(uint value) {
   passAction = value;
}

uint NiStencilProperty::GetDrawMode() const {
   return drawMode;
}

void NiStencilProperty::SetDrawMode(uint value) {
   drawMode = value;
}
