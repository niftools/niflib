/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysSpawnModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysSpawnModifier::TYPE("NiPSysSpawnModifier", &NI_P_SYS_SPAWN_MODIFIER_PARENT::TypeConst() );

NiPSysSpawnModifier::NiPSysSpawnModifier() NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT {}

NiPSysSpawnModifier::~NiPSysSpawnModifier() {}

void NiPSysSpawnModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysSpawnModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysSpawnModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysSpawnModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysSpawnModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysSpawnModifier::GetType() const {
	return TYPE;
};

