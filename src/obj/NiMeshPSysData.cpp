/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMeshPSysData.h"
#include "../../include/obj/NiPSysModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NI_MESH_P_SYS_DATA_PARENT::TypeConst() );

NiMeshPSysData::NiMeshPSysData() NI_MESH_P_SYS_DATA_CONSTRUCT {}

NiMeshPSysData::~NiMeshPSysData() {}

void NiMeshPSysData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiMeshPSysData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiMeshPSysData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMeshPSysData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMeshPSysData::GetType() const {
	return TYPE;
};

