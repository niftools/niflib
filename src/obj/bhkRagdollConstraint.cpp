/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRagdollConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRagdollConstraint::TYPE("bhkRagdollConstraint", &BHK_RAGDOLL_CONSTRAINT_PARENT::TypeConst() );

bhkRagdollConstraint::bhkRagdollConstraint() BHK_RAGDOLL_CONSTRAINT_CONSTRUCT {}

bhkRagdollConstraint::~bhkRagdollConstraint() {}

void bhkRagdollConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkRagdollConstraint::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkRagdollConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRagdollConstraint::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkRagdollConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRagdollConstraint::GetType() const {
	return TYPE;
};

