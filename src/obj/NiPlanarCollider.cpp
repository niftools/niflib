/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPlanarCollider.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPlanarCollider::TYPE("NiPlanarCollider", &NI_PLANAR_COLLIDER_PARENT::TypeConst() );

NiPlanarCollider::NiPlanarCollider() NI_PLANAR_COLLIDER_CONSTRUCT {}

NiPlanarCollider::~NiPlanarCollider() {}

void NiPlanarCollider::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PLANAR_COLLIDER_READ
}

void NiPlanarCollider::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PLANAR_COLLIDER_WRITE
}

string NiPlanarCollider::asString( bool verbose ) const {
	NI_PLANAR_COLLIDER_STRING
}

void NiPlanarCollider::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PLANAR_COLLIDER_FIXLINKS
}

list<NiObjectRef> NiPlanarCollider::GetRefs() const {
	NI_PLANAR_COLLIDER_GETREFS
}

const Type & NiPlanarCollider::GetType() const {
	return TYPE;
};

