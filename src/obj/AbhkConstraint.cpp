/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AbhkConstraint.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AbhkConstraint::TYPE("AbhkConstraint", &ABHK_CONSTRAINT_PARENT::TypeConst() );

AbhkConstraint::AbhkConstraint() ABHK_CONSTRAINT_CONSTRUCT {}

AbhkConstraint::~AbhkConstraint() {}

void AbhkConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void AbhkConstraint::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string AbhkConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AbhkConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> AbhkConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & AbhkConstraint::GetType() const {
	return TYPE;
};

