/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysBombModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysBombModifier::TYPE("NiPSysBombModifier", &NI_P_SYS_BOMB_MODIFIER_PARENT::TypeConst() );

NiPSysBombModifier::NiPSysBombModifier() NI_P_SYS_BOMB_MODIFIER_CONSTRUCT {}

NiPSysBombModifier::~NiPSysBombModifier() {}

void NiPSysBombModifier::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysBombModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysBombModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysBombModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysBombModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysBombModifier::GetType() const {
	return TYPE;
};

