/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiStencilProperty.h"

//Definition of TYPE constant
const Type NiStencilProperty::TYPE("NiStencilProperty", &NI_STENCIL_PROPERTY_PARENT::TYPE );

NiStencilProperty::NiStencilProperty() NI_STENCIL_PROPERTY_CONSTRUCT {}

NiStencilProperty::~NiStencilProperty() {}

void NiStencilProperty::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_STENCIL_PROPERTY_READ
}

void NiStencilProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_STENCIL_PROPERTY_WRITE
}

string NiStencilProperty::asString( bool verbose ) const {
	NI_STENCIL_PROPERTY_STRING
}

void NiStencilProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_STENCIL_PROPERTY_FIXLINKS
}

