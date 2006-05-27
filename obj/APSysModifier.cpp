/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysModifier.h"
#include "NiParticleSystem.h"

//Definition of TYPE constant
const Type APSysModifier::TYPE("APSysModifier", &A_P_SYS_MODIFIER_PARENT::TYPE );

APSysModifier::APSysModifier() A_P_SYS_MODIFIER_CONSTRUCT {}

APSysModifier::~APSysModifier() {}

void APSysModifier::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	A_P_SYS_MODIFIER_READ
}

void APSysModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_P_SYS_MODIFIER_WRITE
}

string APSysModifier::asString( bool verbose ) const {
	A_P_SYS_MODIFIER_STRING
}

void APSysModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	A_P_SYS_MODIFIER_FIXLINKS
}

