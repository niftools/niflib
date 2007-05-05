/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysBoundUpdateModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysBoundUpdateModifier::TYPE("NiPSysBoundUpdateModifier", &NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENT::TYPE );

NiPSysBoundUpdateModifier::NiPSysBoundUpdateModifier() NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT {}

NiPSysBoundUpdateModifier::~NiPSysBoundUpdateModifier() {}

void NiPSysBoundUpdateModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysBoundUpdateModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysBoundUpdateModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysBoundUpdateModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysBoundUpdateModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysBoundUpdateModifier::GetType() const {
	return TYPE;
};
