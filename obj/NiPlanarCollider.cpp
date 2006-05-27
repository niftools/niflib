/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPlanarCollider.h"

//Definition of TYPE constant
const Type NiPlanarCollider::TYPE("NiPlanarCollider", &NI_PLANAR_COLLIDER_PARENT::TYPE );

NiPlanarCollider::NiPlanarCollider() NI_PLANAR_COLLIDER_CONSTRUCT {}

NiPlanarCollider::~NiPlanarCollider() {}

void NiPlanarCollider::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_PLANAR_COLLIDER_READ
}

void NiPlanarCollider::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PLANAR_COLLIDER_WRITE
}

string NiPlanarCollider::asString( bool verbose ) const {
	NI_PLANAR_COLLIDER_STRING
}

void NiPlanarCollider::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_PLANAR_COLLIDER_FIXLINKS
}

