/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysAgeDeathModifier.h"

//Definition of TYPE constant
const Type NiPSysAgeDeathModifier::TYPE("NiPSysAgeDeathModifier", &NI_P_SYS_AGE_DEATH_MODIFIER_PARENT::TYPE );

NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT {}

NiPSysAgeDeathModifier::~NiPSysAgeDeathModifier() {}

void NiPSysAgeDeathModifier::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_P_SYS_AGE_DEATH_MODIFIER_READ
}

void NiPSysAgeDeathModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_P_SYS_AGE_DEATH_MODIFIER_WRITE
}

string NiPSysAgeDeathModifier::asString( bool verbose ) const {
  NI_P_SYS_AGE_DEATH_MODIFIER_STRING
}

void NiPSysAgeDeathModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_P_SYS_AGE_DEATH_MODIFIER_FIXLINKS
}

const Type & NiPSysAgeDeathModifier::GetType() const {
  return TYPE;
};

