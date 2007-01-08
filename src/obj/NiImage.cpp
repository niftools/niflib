/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiImage.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiImage::TYPE("NiImage", &NI_IMAGE_PARENT::TypeConst() );

NiImage::NiImage() NI_IMAGE_CONSTRUCT {}

NiImage::~NiImage() {}

void NiImage::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiImage::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiImage::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiImage::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiImage::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiImage::GetType() const {
	return TYPE;
};

