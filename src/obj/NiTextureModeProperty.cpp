/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextureModeProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureModeProperty::TYPE("NiTextureModeProperty", &NI_TEXTURE_MODE_PROPERTY_PARENT::TypeConst() );

NiTextureModeProperty::NiTextureModeProperty() NI_TEXTURE_MODE_PROPERTY_CONSTRUCT {}

NiTextureModeProperty::~NiTextureModeProperty() {}

void NiTextureModeProperty::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTextureModeProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTextureModeProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextureModeProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTextureModeProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextureModeProperty::GetType() const {
	return TYPE;
};

