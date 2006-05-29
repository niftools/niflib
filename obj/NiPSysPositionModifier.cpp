/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysPositionModifier.h"

//Definition of TYPE constant
const Type NiPSysPositionModifier::TYPE("NiPSysPositionModifier", &NI_P_SYS_POSITION_MODIFIER_PARENT::TYPE );

NiPSysPositionModifier::NiPSysPositionModifier() NI_P_SYS_POSITION_MODIFIER_CONSTRUCT {}

NiPSysPositionModifier::~NiPSysPositionModifier() {}

void NiPSysPositionModifier::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_POSITION_MODIFIER_READ
}

void NiPSysPositionModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_POSITION_MODIFIER_WRITE
}

string NiPSysPositionModifier::asString( bool verbose ) const {
	NI_P_SYS_POSITION_MODIFIER_STRING
}

void NiPSysPositionModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_POSITION_MODIFIER_FIXLINKS
}

