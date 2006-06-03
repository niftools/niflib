/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysBoundUpdateModifier.h"

//Definition of TYPE constant
const Type NiPSysBoundUpdateModifier::TYPE("NiPSysBoundUpdateModifier", &NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENT::TYPE );

NiPSysBoundUpdateModifier::NiPSysBoundUpdateModifier() NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT {}

NiPSysBoundUpdateModifier::~NiPSysBoundUpdateModifier() {}

void NiPSysBoundUpdateModifier::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_P_SYS_BOUND_UPDATE_MODIFIER_READ
}

void NiPSysBoundUpdateModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_P_SYS_BOUND_UPDATE_MODIFIER_WRITE
}

string NiPSysBoundUpdateModifier::asString( bool verbose ) const {
  NI_P_SYS_BOUND_UPDATE_MODIFIER_STRING
}

void NiPSysBoundUpdateModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_P_SYS_BOUND_UPDATE_MODIFIER_FIXLINKS
}

const Type & NiPSysBoundUpdateModifier::GetType() const {
  return TYPE;
};

