/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysSpawnModifier.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiPSysSpawnModifier::TYPE("NiPSysSpawnModifier", &NI_P_SYS_SPAWN_MODIFIER_PARENT::TypeConst() );

NiPSysSpawnModifier::NiPSysSpawnModifier() NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT {}

NiPSysSpawnModifier::~NiPSysSpawnModifier() {}

void NiPSysSpawnModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_SPAWN_MODIFIER_READ
}

void NiPSysSpawnModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_SPAWN_MODIFIER_WRITE
}

string NiPSysSpawnModifier::asString( bool verbose ) const {
	NI_P_SYS_SPAWN_MODIFIER_STRING
}

void NiPSysSpawnModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_SPAWN_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiPSysSpawnModifier::GetRefs() const {
	NI_P_SYS_SPAWN_MODIFIER_GETREFS
}

const Type & NiPSysSpawnModifier::GetType() const {
	return TYPE;
};

