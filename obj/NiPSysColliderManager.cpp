/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysColliderManager.h"
#include "NiPSysPlanarCollider.h"

//Definition of TYPE constant
const Type NiPSysColliderManager::TYPE("NiPSysColliderManager", &NI_P_SYS_COLLIDER_MANAGER_PARENT::TYPE );

NiPSysColliderManager::NiPSysColliderManager() NI_P_SYS_COLLIDER_MANAGER_CONSTRUCT {}

NiPSysColliderManager::~NiPSysColliderManager() {}

void NiPSysColliderManager::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_COLLIDER_MANAGER_READ
}

void NiPSysColliderManager::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_COLLIDER_MANAGER_WRITE
}

string NiPSysColliderManager::asString( bool verbose ) const {
	NI_P_SYS_COLLIDER_MANAGER_STRING
}

void NiPSysColliderManager::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_COLLIDER_MANAGER_FIXLINKS
}

