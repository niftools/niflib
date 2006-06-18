/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiVertexColorProperty.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiVertexColorProperty::TYPE("NiVertexColorProperty", &NI_VERTEX_COLOR_PROPERTY_PARENT::TypeConst() );

NiVertexColorProperty::NiVertexColorProperty() NI_VERTEX_COLOR_PROPERTY_CONSTRUCT {}

NiVertexColorProperty::~NiVertexColorProperty() {}

void NiVertexColorProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VERTEX_COLOR_PROPERTY_READ
}

void NiVertexColorProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_VERTEX_COLOR_PROPERTY_WRITE
}

string NiVertexColorProperty::asString( bool verbose ) const {
	NI_VERTEX_COLOR_PROPERTY_STRING
}

void NiVertexColorProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VERTEX_COLOR_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiVertexColorProperty::GetRefs() const {
	NI_VERTEX_COLOR_PROPERTY_GETREFS
}

const Type & NiVertexColorProperty::GetType() const {
	return TYPE;
};

ushort NiVertexColorProperty::GetFlags() const {
   return flags;
}

void NiVertexColorProperty::SetFlags(ushort value) {
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
