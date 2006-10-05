/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysGrowFadeModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGrowFadeModifier::TYPE("NiPSysGrowFadeModifier", &NI_P_SYS_GROW_FADE_MODIFIER_PARENT::TypeConst() );

NiPSysGrowFadeModifier::NiPSysGrowFadeModifier() NI_P_SYS_GROW_FADE_MODIFIER_CONSTRUCT {}

NiPSysGrowFadeModifier::~NiPSysGrowFadeModifier() {}

void NiPSysGrowFadeModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysGrowFadeModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysGrowFadeModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysGrowFadeModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysGrowFadeModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysGrowFadeModifier::GetType() const {
	return TYPE;
};

