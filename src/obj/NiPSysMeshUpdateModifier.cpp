/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysMeshUpdateModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysMeshUpdateModifier::TYPE("NiPSysMeshUpdateModifier", &NI_P_SYS_MESH_UPDATE_MODIFIER_PARENT::TypeConst() );

NiPSysMeshUpdateModifier::NiPSysMeshUpdateModifier() NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT {}

NiPSysMeshUpdateModifier::~NiPSysMeshUpdateModifier() {}

void NiPSysMeshUpdateModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysMeshUpdateModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysMeshUpdateModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysMeshUpdateModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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
