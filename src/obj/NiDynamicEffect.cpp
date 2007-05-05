/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiDynamicEffect.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDynamicEffect::TYPE("NiDynamicEffect", &NI_DYNAMIC_EFFECT_PARENT::TYPE );

NiDynamicEffect::NiDynamicEffect() NI_DYNAMIC_EFFECT_CONSTRUCT {}

NiDynamicEffect::~NiDynamicEffect() {}

void NiDynamicEffect::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiDynamicEffect::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiDynamicEffect::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiDynamicEffect::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiDynamicEffect::GetRefs() const {
	return InternalGetRefs();
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
