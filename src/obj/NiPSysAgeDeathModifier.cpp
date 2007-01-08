/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysAgeDeathModifier.h"
#include "../../include/obj/NiPSysSpawnModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysAgeDeathModifier::TYPE("NiPSysAgeDeathModifier", &NI_P_SYS_AGE_DEATH_MODIFIER_PARENT::TypeConst() );

NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT {}

NiPSysAgeDeathModifier::~NiPSysAgeDeathModifier() {}

void NiPSysAgeDeathModifier::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysAgeDeathModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysAgeDeathModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysAgeDeathModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysAgeDeathModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysAgeDeathModifier::GetType() const {
	return TYPE;
};

