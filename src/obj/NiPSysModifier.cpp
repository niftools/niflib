/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysModifier.h"
#include "../../include/obj/NiParticleSystem.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysModifier::TYPE("NiPSysModifier", &NI_P_SYS_MODIFIER_PARENT::TypeConst() );

NiPSysModifier::NiPSysModifier() NI_P_SYS_MODIFIER_CONSTRUCT {}

NiPSysModifier::~NiPSysModifier() {}

void NiPSysModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysModifier::GetType() const {
	return TYPE;
};

