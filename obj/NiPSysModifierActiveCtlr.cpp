/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysModifierActiveCtlr.h"

//Definition of TYPE constant
const Type NiPSysModifierActiveCtlr::TYPE("NiPSysModifierActiveCtlr", &NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENT::TYPE );

NiPSysModifierActiveCtlr::NiPSysModifierActiveCtlr() NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT {}

NiPSysModifierActiveCtlr::~NiPSysModifierActiveCtlr() {}

void NiPSysModifierActiveCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_P_SYS_MODIFIER_ACTIVE_CTLR_READ
}

void NiPSysModifierActiveCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_P_SYS_MODIFIER_ACTIVE_CTLR_WRITE
}

string NiPSysModifierActiveCtlr::asString( bool verbose ) const {
  NI_P_SYS_MODIFIER_ACTIVE_CTLR_STRING
}

void NiPSysModifierActiveCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_P_SYS_MODIFIER_ACTIVE_CTLR_FIXLINKS
}

const Type & NiPSysModifierActiveCtlr::GetType() const {
  return TYPE;
};

