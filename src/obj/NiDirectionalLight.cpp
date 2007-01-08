/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiDirectionalLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDirectionalLight::TYPE("NiDirectionalLight", &NI_DIRECTIONAL_LIGHT_PARENT::TypeConst() );

NiDirectionalLight::NiDirectionalLight() NI_DIRECTIONAL_LIGHT_CONSTRUCT {}

NiDirectionalLight::~NiDirectionalLight() {}

void NiDirectionalLight::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiDirectionalLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiDirectionalLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiDirectionalLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiDirectionalLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiDirectionalLight::GetType() const {
	return TYPE;
};

