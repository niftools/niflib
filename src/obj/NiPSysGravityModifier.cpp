/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysGravityModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGravityModifier::TYPE("NiPSysGravityModifier", &NI_P_SYS_GRAVITY_MODIFIER_PARENT::TYPE );

NiPSysGravityModifier::NiPSysGravityModifier() NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT {}

NiPSysGravityModifier::~NiPSysGravityModifier() {}

void NiPSysGravityModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysGravityModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysGravityModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysGravityModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysGravityModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysGravityModifier::GetType() const {
	return TYPE;
};
