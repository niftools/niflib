/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSParentVelocityModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSParentVelocityModifier::TYPE("BSParentVelocityModifier", &B_S_PARENT_VELOCITY_MODIFIER_PARENT::TypeConst() );

BSParentVelocityModifier::BSParentVelocityModifier() B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT {}

BSParentVelocityModifier::~BSParentVelocityModifier() {}

void BSParentVelocityModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void BSParentVelocityModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string BSParentVelocityModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSParentVelocityModifier::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> BSParentVelocityModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSParentVelocityModifier::GetType() const {
	return TYPE;
};

