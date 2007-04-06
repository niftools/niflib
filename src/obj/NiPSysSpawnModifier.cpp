/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysSpawnModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysSpawnModifier::TYPE("NiPSysSpawnModifier", &NI_P_SYS_SPAWN_MODIFIER_PARENT::TypeConst() );

NiPSysSpawnModifier::NiPSysSpawnModifier() NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT {}

NiPSysSpawnModifier::~NiPSysSpawnModifier() {}

void NiPSysSpawnModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysSpawnModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysSpawnModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysSpawnModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysSpawnModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysSpawnModifier::GetType() const {
	return TYPE;
};

const Type & NiPSysSpawnModifier::TypeConst() {
	return TYPE;
}
