/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAmbientLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAmbientLight::TYPE("NiAmbientLight", &NI_AMBIENT_LIGHT_PARENT::TypeConst() );

NiAmbientLight::NiAmbientLight() NI_AMBIENT_LIGHT_CONSTRUCT {}

NiAmbientLight::~NiAmbientLight() {}

void NiAmbientLight::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiAmbientLight::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiAmbientLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAmbientLight::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiAmbientLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAmbientLight::GetType() const {
	return TYPE;
};

