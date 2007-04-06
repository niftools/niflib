/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPlanarCollider.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPlanarCollider::TYPE("NiPlanarCollider", &NI_PLANAR_COLLIDER_PARENT::TypeConst() );

NiPlanarCollider::NiPlanarCollider() NI_PLANAR_COLLIDER_CONSTRUCT {}

NiPlanarCollider::~NiPlanarCollider() {}

void NiPlanarCollider::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPlanarCollider::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPlanarCollider::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPlanarCollider::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPlanarCollider::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPlanarCollider::GetType() const {
	return TYPE;
};

const Type & NiPlanarCollider::TypeConst() {
	return TYPE;
}
