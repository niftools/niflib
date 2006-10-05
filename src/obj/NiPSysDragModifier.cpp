/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysDragModifier.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysDragModifier::TYPE("NiPSysDragModifier", &NI_P_SYS_DRAG_MODIFIER_PARENT::TypeConst() );

NiPSysDragModifier::NiPSysDragModifier() NI_P_SYS_DRAG_MODIFIER_CONSTRUCT {}

NiPSysDragModifier::~NiPSysDragModifier() {}

void NiPSysDragModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysDragModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysDragModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysDragModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysDragModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysDragModifier::GetType() const {
	return TYPE;
};

