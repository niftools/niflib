/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiProperty::TYPE("NiProperty", &NI_PROPERTY_PARENT::TypeConst() );

NiProperty::NiProperty() NI_PROPERTY_CONSTRUCT {}

NiProperty::~NiProperty() {}

void NiProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiProperty::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiProperty::GetType() const {
	return TYPE;
};

