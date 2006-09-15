/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiMeshPSysData.h"
#include "NiPSysModifier.h"
#include "NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NI_MESH_P_SYS_DATA_PARENT::TypeConst() );

NiMeshPSysData::NiMeshPSysData() NI_MESH_P_SYS_DATA_CONSTRUCT {}

NiMeshPSysData::~NiMeshPSysData() {}

void NiMeshPSysData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MESH_P_SYS_DATA_READ
}

void NiMeshPSysData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_MESH_P_SYS_DATA_WRITE
}

string NiMeshPSysData::asString( bool verbose ) const {
	NI_MESH_P_SYS_DATA_STRING
}

void NiMeshPSysData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MESH_P_SYS_DATA_FIXLINKS
}

list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	NI_MESH_P_SYS_DATA_GETREFS
}

const Type & NiMeshPSysData::GetType() const {
	return TYPE;
};

