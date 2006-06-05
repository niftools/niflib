/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysGrowFadeModifier.h"

//Definition of TYPE constant
const Type NiPSysGrowFadeModifier::TYPE("NiPSysGrowFadeModifier", &NI_P_SYS_GROW_FADE_MODIFIER_PARENT::TYPE );

NiPSysGrowFadeModifier::NiPSysGrowFadeModifier() NI_P_SYS_GROW_FADE_MODIFIER_CONSTRUCT {}

NiPSysGrowFadeModifier::~NiPSysGrowFadeModifier() {}

void NiPSysGrowFadeModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_GROW_FADE_MODIFIER_READ
}

void NiPSysGrowFadeModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_GROW_FADE_MODIFIER_WRITE
}

string NiPSysGrowFadeModifier::asString( bool verbose ) const {
	NI_P_SYS_GROW_FADE_MODIFIER_STRING
}

void NiPSysGrowFadeModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_GROW_FADE_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiPSysGrowFadeModifier::GetRefs() const {
	NI_P_SYS_GROW_FADE_MODIFIER_GETREFS
}

const Type & NiPSysGrowFadeModifier::GetType() const {
	return TYPE;
};

