/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSParentVelocityModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSParentVelocityModifier::TYPE("BSParentVelocityModifier", &B_S_PARENT_VELOCITY_MODIFIER_PARENT::TypeConst() );

BSParentVelocityModifier::BSParentVelocityModifier() B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT {}

BSParentVelocityModifier::~BSParentVelocityModifier() {}

void BSParentVelocityModifier::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void BSParentVelocityModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string BSParentVelocityModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSParentVelocityModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> BSParentVelocityModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSParentVelocityModifier::GetType() const {
	return TYPE;
};

