/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysRotationModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysRotationModifier::TYPE("NiPSysRotationModifier", &NI_P_SYS_ROTATION_MODIFIER_PARENT::TYPE );

NiPSysRotationModifier::NiPSysRotationModifier() NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT {}

NiPSysRotationModifier::~NiPSysRotationModifier() {}

void NiPSysRotationModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysRotationModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysRotationModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysRotationModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysRotationModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysRotationModifier::GetType() const {
	return TYPE;
};
