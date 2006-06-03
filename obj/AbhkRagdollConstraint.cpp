/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/AbhkRagdollConstraint.h"

//Definition of TYPE constant
const Type AbhkRagdollConstraint::TYPE("AbhkRagdollConstraint", &ABHK_RAGDOLL_CONSTRAINT_PARENT::TYPE );

AbhkRagdollConstraint::AbhkRagdollConstraint() ABHK_RAGDOLL_CONSTRAINT_CONSTRUCT {}

AbhkRagdollConstraint::~AbhkRagdollConstraint() {}

void AbhkRagdollConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  ABHK_RAGDOLL_CONSTRAINT_READ
}

void AbhkRagdollConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  ABHK_RAGDOLL_CONSTRAINT_WRITE
}

string AbhkRagdollConstraint::asString( bool verbose ) const {
  ABHK_RAGDOLL_CONSTRAINT_STRING
}

void AbhkRagdollConstraint::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  ABHK_RAGDOLL_CONSTRAINT_FIXLINKS
}

const Type & AbhkRagdollConstraint::GetType() const {
  return TYPE;
};

