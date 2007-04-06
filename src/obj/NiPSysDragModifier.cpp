/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysDragModifier.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysDragModifier::TYPE("NiPSysDragModifier", &NI_P_SYS_DRAG_MODIFIER_PARENT::TypeConst() );

NiPSysDragModifier::NiPSysDragModifier() NI_P_SYS_DRAG_MODIFIER_CONSTRUCT {}

NiPSysDragModifier::~NiPSysDragModifier() {}

void NiPSysDragModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysDragModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysDragModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysDragModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysDragModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysDragModifier::GetType() const {
	return TYPE;
};

const Type & NiPSysDragModifier::TypeConst() {
	return TYPE;
}
