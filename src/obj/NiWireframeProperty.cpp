/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiWireframeProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiWireframeProperty::TYPE("NiWireframeProperty", &NI_WIREFRAME_PROPERTY_PARENT::TYPE );

NiWireframeProperty::NiWireframeProperty() NI_WIREFRAME_PROPERTY_CONSTRUCT {}

NiWireframeProperty::~NiWireframeProperty() {}

void NiWireframeProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiWireframeProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiWireframeProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiWireframeProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiWireframeProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiWireframeProperty::GetType() const {
	return TYPE;
};

unsigned short NiWireframeProperty::GetFlags() const {
   return flags;
}

void NiWireframeProperty::SetFlags(unsigned short value) {
   flags = value;
}
