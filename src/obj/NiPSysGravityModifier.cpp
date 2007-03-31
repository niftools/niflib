/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysGravityModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGravityModifier::TYPE("NiPSysGravityModifier", &NI_P_SYS_GRAVITY_MODIFIER_PARENT::TypeConst() );

NiPSysGravityModifier::NiPSysGravityModifier() NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT {}

NiPSysGravityModifier::~NiPSysGravityModifier() {}

void NiPSysGravityModifier::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysGravityModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysGravityModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysGravityModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysGravityModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysGravityModifier::GetType() const {
	return TYPE;
};

const Type & NiPSysGravityModifier::TypeConst() {
	return TYPE;
}
