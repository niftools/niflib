/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkRagdollConstraint.h"

//Definition of TYPE constant
const Type bhkRagdollConstraint::TYPE("bhkRagdollConstraint", &BHK_RAGDOLL_CONSTRAINT_PARENT::TYPE );

bhkRagdollConstraint::bhkRagdollConstraint() BHK_RAGDOLL_CONSTRAINT_CONSTRUCT {}

bhkRagdollConstraint::~bhkRagdollConstraint() {}

void bhkRagdollConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  BHK_RAGDOLL_CONSTRAINT_READ
}

void bhkRagdollConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  BHK_RAGDOLL_CONSTRAINT_WRITE
}

string bhkRagdollConstraint::asString( bool verbose ) const {
  BHK_RAGDOLL_CONSTRAINT_STRING
}

void bhkRagdollConstraint::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  BHK_RAGDOLL_CONSTRAINT_FIXLINKS
}

const Type & bhkRagdollConstraint::GetType() const {
  return TYPE;
};

