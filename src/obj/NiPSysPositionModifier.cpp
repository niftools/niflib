/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysPositionModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysPositionModifier::TYPE("NiPSysPositionModifier", &NI_P_SYS_POSITION_MODIFIER_PARENT::TypeConst() );

NiPSysPositionModifier::NiPSysPositionModifier() NI_P_SYS_POSITION_MODIFIER_CONSTRUCT {}

NiPSysPositionModifier::~NiPSysPositionModifier() {}

void NiPSysPositionModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysPositionModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysPositionModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysPositionModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysPositionModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysPositionModifier::GetType() const {
	return TYPE;
};

