/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysBoundUpdateModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysBoundUpdateModifier::TYPE("NiPSysBoundUpdateModifier", &NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENT::TypeConst() );

NiPSysBoundUpdateModifier::NiPSysBoundUpdateModifier() NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT {}

NiPSysBoundUpdateModifier::~NiPSysBoundUpdateModifier() {}

void NiPSysBoundUpdateModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysBoundUpdateModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysBoundUpdateModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysBoundUpdateModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysBoundUpdateModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysBoundUpdateModifier::GetType() const {
	return TYPE;
};

