/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysPlanarCollider.h"
#include "../../include/obj/NiPSysSpawnModifier.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysPlanarCollider::TYPE("NiPSysPlanarCollider", &NI_P_SYS_PLANAR_COLLIDER_PARENT::TypeConst() );

NiPSysPlanarCollider::NiPSysPlanarCollider() NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT {}

NiPSysPlanarCollider::~NiPSysPlanarCollider() {}

void NiPSysPlanarCollider::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysPlanarCollider::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysPlanarCollider::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysPlanarCollider::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysPlanarCollider::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysPlanarCollider::GetType() const {
	return TYPE;
};

