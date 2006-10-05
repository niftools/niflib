/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysColorModifier.h"
#include "../../include/obj/NiColorData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysColorModifier::TYPE("NiPSysColorModifier", &NI_P_SYS_COLOR_MODIFIER_PARENT::TypeConst() );

NiPSysColorModifier::NiPSysColorModifier() NI_P_SYS_COLOR_MODIFIER_CONSTRUCT {}

NiPSysColorModifier::~NiPSysColorModifier() {}

void NiPSysColorModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysColorModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysColorModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysColorModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysColorModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysColorModifier::GetType() const {
	return TYPE;
};

