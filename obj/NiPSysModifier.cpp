/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysModifier.h"
#include "obj/NiParticleSystem.h"

//Definition of TYPE constant
const Type NiPSysModifier::TYPE("NiPSysModifier", &NI_P_SYS_MODIFIER_PARENT::TYPE );

NiPSysModifier::NiPSysModifier() NI_P_SYS_MODIFIER_CONSTRUCT {}

NiPSysModifier::~NiPSysModifier() {}

void NiPSysModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_MODIFIER_READ
}

void NiPSysModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_MODIFIER_WRITE
}

string NiPSysModifier::asString( bool verbose ) const {
	NI_P_SYS_MODIFIER_STRING
}

void NiPSysModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiPSysModifier::GetRefs() const {
	NI_P_SYS_MODIFIER_GETREFS
}

const Type & NiPSysModifier::GetType() const {
	return TYPE;
};

