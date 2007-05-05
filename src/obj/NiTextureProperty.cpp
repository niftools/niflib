/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextureProperty.h"
#include "../../include/obj/NiImage.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureProperty::TYPE("NiTextureProperty", &NI_TEXTURE_PROPERTY_PARENT::TYPE );

NiTextureProperty::NiTextureProperty() NI_TEXTURE_PROPERTY_CONSTRUCT {}

NiTextureProperty::~NiTextureProperty() {}

void NiTextureProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTextureProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTextureProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextureProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTextureProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextureProperty::GetType() const {
	return TYPE;
};
