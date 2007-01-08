/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysColliderManager.h"
#include "../../include/obj/NiPSysPlanarCollider.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysColliderManager::TYPE("NiPSysColliderManager", &NI_P_SYS_COLLIDER_MANAGER_PARENT::TypeConst() );

NiPSysColliderManager::NiPSysColliderManager() NI_P_SYS_COLLIDER_MANAGER_CONSTRUCT {}

NiPSysColliderManager::~NiPSysColliderManager() {}

void NiPSysColliderManager::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysColliderManager::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysColliderManager::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysColliderManager::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysColliderManager::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysColliderManager::GetType() const {
	return TYPE;
};

