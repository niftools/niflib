/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysMeshUpdateModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysMeshUpdateModifier::TYPE("NiPSysMeshUpdateModifier", &NI_P_SYS_MESH_UPDATE_MODIFIER_PARENT::TypeConst() );

NiPSysMeshUpdateModifier::NiPSysMeshUpdateModifier() NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT {}

NiPSysMeshUpdateModifier::~NiPSysMeshUpdateModifier() {}

void NiPSysMeshUpdateModifier::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysMeshUpdateModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysMeshUpdateModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysMeshUpdateModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysMeshUpdateModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysMeshUpdateModifier::GetType() const {
	return TYPE;
};

const Type & NiPSysMeshUpdateModifier::TypeConst() {
	return TYPE;
}
