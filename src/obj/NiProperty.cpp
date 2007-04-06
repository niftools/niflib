/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiProperty::TYPE("NiProperty", &NI_PROPERTY_PARENT::TypeConst() );

NiProperty::NiProperty() NI_PROPERTY_CONSTRUCT {}

NiProperty::~NiProperty() {}

void NiProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiProperty::GetType() const {
	return TYPE;
};

const Type & NiProperty::TypeConst() {
	return TYPE;
}
