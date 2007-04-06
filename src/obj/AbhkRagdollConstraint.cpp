/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AbhkRagdollConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AbhkRagdollConstraint::TYPE("AbhkRagdollConstraint", &ABHK_RAGDOLL_CONSTRAINT_PARENT::TypeConst() );

AbhkRagdollConstraint::AbhkRagdollConstraint() ABHK_RAGDOLL_CONSTRAINT_CONSTRUCT {}

AbhkRagdollConstraint::~AbhkRagdollConstraint() {}

void AbhkRagdollConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void AbhkRagdollConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string AbhkRagdollConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AbhkRagdollConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> AbhkRagdollConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & AbhkRagdollConstraint::GetType() const {
	return TYPE;
};

const Type & AbhkRagdollConstraint::TypeConst() {
	return TYPE;
}
