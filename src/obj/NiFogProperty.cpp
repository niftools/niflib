/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFogProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFogProperty::TYPE("NiFogProperty", &NI_FOG_PROPERTY_PARENT::TypeConst() );

NiFogProperty::NiFogProperty() NI_FOG_PROPERTY_CONSTRUCT {}

NiFogProperty::~NiFogProperty() {}

void NiFogProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiFogProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiFogProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFogProperty::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiFogProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFogProperty::GetType() const {
	return TYPE;
};


ushort NiFogProperty::GetFlags() const {
   return flags;
}

void NiFogProperty::SetFlags( ushort n ) {
   flags = n;
}

float NiFogProperty::GetFogDepth() const {
   return fogDepth;
}

void NiFogProperty::SetFogDepth(float value) {
   fogDepth = value;
}

Color3 NiFogProperty::GetFogColor() const {
   return fogColor;
}

void NiFogProperty::SetFogColor(Color3 value) {
   fogColor = value;
}
