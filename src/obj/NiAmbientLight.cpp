/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAmbientLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAmbientLight::TYPE("NiAmbientLight", &NI_AMBIENT_LIGHT_PARENT::TypeConst() );

NiAmbientLight::NiAmbientLight() NI_AMBIENT_LIGHT_CONSTRUCT {}

NiAmbientLight::~NiAmbientLight() {}

void NiAmbientLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAmbientLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAmbientLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAmbientLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAmbientLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAmbientLight::GetType() const {
	return TYPE;
};

const Type & NiAmbientLight::TypeConst() {
	return TYPE;
}
