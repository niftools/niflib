/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysMeshUpdateModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysMeshUpdateModifier::TYPE("NiPSysMeshUpdateModifier", &NI_P_SYS_MESH_UPDATE_MODIFIER_PARENT::TypeConst() );

NiPSysMeshUpdateModifier::NiPSysMeshUpdateModifier() NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT {}

NiPSysMeshUpdateModifier::~NiPSysMeshUpdateModifier() {}

void NiPSysMeshUpdateModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_MESH_UPDATE_MODIFIER_READ
}

void NiPSysMeshUpdateModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_MESH_UPDATE_MODIFIER_WRITE
}

string NiPSysMeshUpdateModifier::asString( bool verbose ) const {
	NI_P_SYS_MESH_UPDATE_MODIFIER_STRING
}

void NiPSysMeshUpdateModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_MESH_UPDATE_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiPSysMeshUpdateModifier::GetRefs() const {
	NI_P_SYS_MESH_UPDATE_MODIFIER_GETREFS
}

const Type & NiPSysMeshUpdateModifier::GetType() const {
	return TYPE;
};

