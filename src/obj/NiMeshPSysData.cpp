/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMeshPSysData.h"
#include "../../include/obj/NiPSysModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NI_MESH_P_SYS_DATA_PARENT::TYPE );

NiMeshPSysData::NiMeshPSysData() NI_MESH_P_SYS_DATA_CONSTRUCT {}

NiMeshPSysData::~NiMeshPSysData() {}

void NiMeshPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiMeshPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiMeshPSysData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMeshPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMeshPSysData::GetType() const {
	return TYPE;
};
