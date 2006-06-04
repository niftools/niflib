/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiDynamicEffect.h"
#include "obj/NiAVObject.h"

//Definition of TYPE constant
const Type NiDynamicEffect::TYPE("NiDynamicEffect", &NI_DYNAMIC_EFFECT_PARENT::TYPE );

NiDynamicEffect::NiDynamicEffect() NI_DYNAMIC_EFFECT_CONSTRUCT {}

NiDynamicEffect::~NiDynamicEffect() {}

void NiDynamicEffect::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_DYNAMIC_EFFECT_READ
}

void NiDynamicEffect::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_DYNAMIC_EFFECT_WRITE
}

string NiDynamicEffect::asString( bool verbose ) const {
	NI_DYNAMIC_EFFECT_STRING
}

void NiDynamicEffect::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_DYNAMIC_EFFECT_FIXLINKS
}

const Type & NiDynamicEffect::GetType() const {
	return TYPE;
};

