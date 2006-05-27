/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysDragModifier.h"

//Definition of TYPE constant
const Type NiPSysDragModifier::TYPE("NiPSysDragModifier", &NI_P_SYS_DRAG_MODIFIER_PARENT::TYPE );

NiPSysDragModifier::NiPSysDragModifier() NI_P_SYS_DRAG_MODIFIER_CONSTRUCT {}

NiPSysDragModifier::~NiPSysDragModifier() {}

void NiPSysDragModifier::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_DRAG_MODIFIER_READ
}

void NiPSysDragModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_DRAG_MODIFIER_WRITE
}

string NiPSysDragModifier::asString( bool verbose ) const {
	NI_P_SYS_DRAG_MODIFIER_STRING
}

void NiPSysDragModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_DRAG_MODIFIER_FIXLINKS
}

