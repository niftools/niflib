/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysAgeDeathModifier.h"
#include "NiPSysSpawnModifier.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiPSysAgeDeathModifier::TYPE("NiPSysAgeDeathModifier", &NI_P_SYS_AGE_DEATH_MODIFIER_PARENT::TypeConst() );

NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT {}

NiPSysAgeDeathModifier::~NiPSysAgeDeathModifier() {}

void NiPSysAgeDeathModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_AGE_DEATH_MODIFIER_READ
}

void NiPSysAgeDeathModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_AGE_DEATH_MODIFIER_WRITE
}

string NiPSysAgeDeathModifier::asString( bool verbose ) const {
	NI_P_SYS_AGE_DEATH_MODIFIER_STRING
}

void NiPSysAgeDeathModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_AGE_DEATH_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiPSysAgeDeathModifier::GetRefs() const {
	NI_P_SYS_AGE_DEATH_MODIFIER_GETREFS
}

const Type & NiPSysAgeDeathModifier::GetType() const {
	return TYPE;
};

