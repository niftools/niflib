/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysPlanarCollider.h"
#include "NiPSysSpawnModifier.h"
#include "NiNode.h"

//Definition of TYPE constant
const Type NiPSysPlanarCollider::TYPE("NiPSysPlanarCollider", &NI_P_SYS_PLANAR_COLLIDER_PARENT::TYPE );

NiPSysPlanarCollider::NiPSysPlanarCollider() NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT {}

NiPSysPlanarCollider::~NiPSysPlanarCollider() {}

void NiPSysPlanarCollider::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_PLANAR_COLLIDER_READ
}

void NiPSysPlanarCollider::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_PLANAR_COLLIDER_WRITE
}

string NiPSysPlanarCollider::asString( bool verbose ) const {
	NI_P_SYS_PLANAR_COLLIDER_STRING
}

void NiPSysPlanarCollider::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_PLANAR_COLLIDER_FIXLINKS
}

