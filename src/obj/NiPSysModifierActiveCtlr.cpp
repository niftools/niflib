/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysModifierActiveCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysModifierActiveCtlr::TYPE("NiPSysModifierActiveCtlr", &NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENT::TypeConst() );

NiPSysModifierActiveCtlr::NiPSysModifierActiveCtlr() NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT {}

NiPSysModifierActiveCtlr::~NiPSysModifierActiveCtlr() {}

void NiPSysModifierActiveCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysModifierActiveCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysModifierActiveCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysModifierActiveCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysModifierActiveCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysModifierActiveCtlr::GetType() const {
	return TYPE;
};

const Type & NiPSysModifierActiveCtlr::TypeConst() {
	return TYPE;
}
