/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysModifierActiveCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysModifierActiveCtlr::TYPE("NiPSysModifierActiveCtlr", &NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENT::TypeConst() );

NiPSysModifierActiveCtlr::NiPSysModifierActiveCtlr() NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT {}

NiPSysModifierActiveCtlr::~NiPSysModifierActiveCtlr() {}

void NiPSysModifierActiveCtlr::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysModifierActiveCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysModifierActiveCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysModifierActiveCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysModifierActiveCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysModifierActiveCtlr::GetType() const {
	return TYPE;
};

