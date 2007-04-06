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

void NiPSysPlanarCollider::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysPlanarCollider::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysPlanarCollider::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysPlanarCollider::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysPlanarCollider::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysPlanarCollider::GetType() const {
	return TYPE;
};

const Type & NiPSysPlanarCollider::TypeConst() {
	return TYPE;
}
