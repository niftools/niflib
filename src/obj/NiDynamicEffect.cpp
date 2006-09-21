/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiDynamicEffect.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDynamicEffect::TYPE("NiDynamicEffect", &NI_DYNAMIC_EFFECT_PARENT::TypeConst() );

NiDynamicEffect::NiDynamicEffect() NI_DYNAMIC_EFFECT_CONSTRUCT {}

NiDynamicEffect::~NiDynamicEffect() {}

void NiDynamicEffect::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DYNAMIC_EFFECT_READ
}

void NiDynamicEffect::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_DYNAMIC_EFFECT_WRITE
}

string NiDynamicEffect::asString( bool verbose ) const {
	NI_DYNAMIC_EFFECT_STRING
}

void NiDynamicEffect::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DYNAMIC_EFFECT_FIXLINKS
}

list<NiObjectRef> NiDynamicEffect::GetRefs() const {
	NI_DYNAMIC_EFFECT_GETREFS
}

const Type & NiDynamicEffect::GetType() const {
	return TYPE;
};

bool NiDynamicEffect::GetSwitchState() const {
	return switchState;
}

void NiDynamicEffect::SetSwitchState( bool value ) {
	switchState = value;
}

vector<Ref<NiAVObject > > NiDynamicEffect::GetAffectedNodes() const {
	return affectedNodes;
}

void NiDynamicEffect::SetAffectedNodes( const vector<Ref<NiAVObject > >& value ) {
	affectedNodes = value;
}

vector<uint > NiDynamicEffect::GetAffectedNodeListPointers() const {
	return affectedNodeListPointers;
}

void NiDynamicEffect::SetAffectedNodeListPointers( const vector<uint >& value ) {
	affectedNodeListPointers = value;
}

