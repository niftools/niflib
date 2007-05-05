/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysAgeDeathModifier.h"
#include "../../include/obj/NiPSysSpawnModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysAgeDeathModifier::TYPE("NiPSysAgeDeathModifier", &NI_P_SYS_AGE_DEATH_MODIFIER_PARENT::TYPE );

NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT {}

NiPSysAgeDeathModifier::~NiPSysAgeDeathModifier() {}

void NiPSysAgeDeathModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysAgeDeathModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysAgeDeathModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysAgeDeathModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysAgeDeathModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysAgeDeathModifier::GetType() const {
	return TYPE;
};
