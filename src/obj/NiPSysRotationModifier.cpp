/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysRotationModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysRotationModifier::TYPE("NiPSysRotationModifier", &NI_P_SYS_ROTATION_MODIFIER_PARENT::TypeConst() );

NiPSysRotationModifier::NiPSysRotationModifier() NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT {}

NiPSysRotationModifier::~NiPSysRotationModifier() {}

void NiPSysRotationModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysRotationModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysRotationModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysRotationModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysRotationModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysRotationModifier::GetType() const {
	return TYPE;
};

