/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextureProperty.h"
#include "../../include/obj/NiImage.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureProperty::TYPE("NiTextureProperty", &NI_TEXTURE_PROPERTY_PARENT::TypeConst() );

NiTextureProperty::NiTextureProperty() NI_TEXTURE_PROPERTY_CONSTRUCT {}

NiTextureProperty::~NiTextureProperty() {}

void NiTextureProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTextureProperty::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTextureProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextureProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTextureProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextureProperty::GetType() const {
	return TYPE;
};

