/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiVertexColorProperty.h"

//Definition of TYPE constant
const Type NiVertexColorProperty::TYPE("NiVertexColorProperty", &NI_VERTEX_COLOR_PROPERTY_PARENT::TYPE );

NiVertexColorProperty::NiVertexColorProperty() NI_VERTEX_COLOR_PROPERTY_CONSTRUCT {}

NiVertexColorProperty::~NiVertexColorProperty() {}

void NiVertexColorProperty::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_VERTEX_COLOR_PROPERTY_READ
}

void NiVertexColorProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_VERTEX_COLOR_PROPERTY_WRITE
}

string NiVertexColorProperty::asString( bool verbose ) const {
	NI_VERTEX_COLOR_PROPERTY_STRING
}

void NiVertexColorProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_VERTEX_COLOR_PROPERTY_FIXLINKS
}

const Type & NiVertexColorProperty::GetType() const {
	return TYPE;
};

