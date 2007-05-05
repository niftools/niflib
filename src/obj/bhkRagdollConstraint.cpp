/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRagdollConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRagdollConstraint::TYPE("bhkRagdollConstraint", &BHK_RAGDOLL_CONSTRAINT_PARENT::TYPE );

bhkRagdollConstraint::bhkRagdollConstraint() BHK_RAGDOLL_CONSTRAINT_CONSTRUCT {}

bhkRagdollConstraint::~bhkRagdollConstraint() {}

void bhkRagdollConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkRagdollConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkRagdollConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRagdollConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkRagdollConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRagdollConstraint::GetType() const {
	return TYPE;
};
