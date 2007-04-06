/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AbhkConstraint.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AbhkConstraint::TYPE("AbhkConstraint", &ABHK_CONSTRAINT_PARENT::TypeConst() );

AbhkConstraint::AbhkConstraint() ABHK_CONSTRAINT_CONSTRUCT {}

AbhkConstraint::~AbhkConstraint() {}

void AbhkConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void AbhkConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string AbhkConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AbhkConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> AbhkConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & AbhkConstraint::GetType() const {
	return TYPE;
};

const Type & AbhkConstraint::TypeConst() {
	return TYPE;
}
