/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysRotationModifier.h"

//Definition of TYPE constant
const Type NiPSysRotationModifier::TYPE("NiPSysRotationModifier", &NI_P_SYS_ROTATION_MODIFIER_PARENT::TYPE );

NiPSysRotationModifier::NiPSysRotationModifier() NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT {}

NiPSysRotationModifier::~NiPSysRotationModifier() {}

void NiPSysRotationModifier::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_ROTATION_MODIFIER_READ
}

void NiPSysRotationModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_ROTATION_MODIFIER_WRITE
}

string NiPSysRotationModifier::asString( bool verbose ) const {
	NI_P_SYS_ROTATION_MODIFIER_STRING
}

void NiPSysRotationModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_ROTATION_MODIFIER_FIXLINKS
}

