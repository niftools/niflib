/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkRagdollConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRagdollConstraint::TYPE("bhkRagdollConstraint", &BHK_RAGDOLL_CONSTRAINT_PARENT::TypeConst() );

bhkRagdollConstraint::bhkRagdollConstraint() BHK_RAGDOLL_CONSTRAINT_CONSTRUCT {}

bhkRagdollConstraint::~bhkRagdollConstraint() {}

void bhkRagdollConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_RAGDOLL_CONSTRAINT_READ
}

void bhkRagdollConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_RAGDOLL_CONSTRAINT_WRITE
}

string bhkRagdollConstraint::asString( bool verbose ) const {
	BHK_RAGDOLL_CONSTRAINT_STRING
}

void bhkRagdollConstraint::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_RAGDOLL_CONSTRAINT_FIXLINKS
}

list<NiObjectRef> bhkRagdollConstraint::GetRefs() const {
	BHK_RAGDOLL_CONSTRAINT_GETREFS
}

const Type & bhkRagdollConstraint::GetType() const {
	return TYPE;
};

