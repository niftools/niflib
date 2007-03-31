/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVertexColorProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVertexColorProperty::TYPE("NiVertexColorProperty", &NI_VERTEX_COLOR_PROPERTY_PARENT::TypeConst() );

NiVertexColorProperty::NiVertexColorProperty() NI_VERTEX_COLOR_PROPERTY_CONSTRUCT {}

NiVertexColorProperty::~NiVertexColorProperty() {}

void NiVertexColorProperty::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiVertexColorProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiVertexColorProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVertexColorProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

const Type & NiVertexColorProperty::TypeConst() {
	return TYPE;
}
