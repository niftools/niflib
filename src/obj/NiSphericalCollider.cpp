/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSphericalCollider.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSphericalCollider::TYPE("NiSphericalCollider", &NI_SPHERICAL_COLLIDER_PARENT::TypeConst() );

NiSphericalCollider::NiSphericalCollider() NI_SPHERICAL_COLLIDER_CONSTRUCT {}

NiSphericalCollider::~NiSphericalCollider() {}

void NiSphericalCollider::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiSphericalCollider::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiSphericalCollider::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSphericalCollider::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiSphericalCollider::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSphericalCollider::GetType() const {
	return TYPE;
};

