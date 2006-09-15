/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiDynamicEffect.h"
#include "NiAVObject.h"
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

void NiDynamicEffect::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_DYNAMIC_EFFECT_FIXLINKS
}

list<NiObjectRef> NiDynamicEffect::GetRefs() const {
	NI_DYNAMIC_EFFECT_GETREFS
}

const Type & NiDynamicEffect::GetType() const {
	return TYPE;
};

bool NiDynamicEffect::GetHasAffectedNodeList_() const {
	return hasAffectedNodeList_;
}

void NiDynamicEffect::SetHasAffectedNodeList_( bool value ) {
	hasAffectedNodeList_ = value;
}

uint NiDynamicEffect::GetAffectedNodeList_() const {
	return affectedNodeList_;
}

void NiDynamicEffect::SetAffectedNodeList_( uint value ) {
	affectedNodeList_ = value;
}

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

