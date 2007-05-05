/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkHingeConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkHingeConstraint::TYPE("bhkHingeConstraint", &BHK_HINGE_CONSTRAINT_PARENT::TYPE );

bhkHingeConstraint::bhkHingeConstraint() BHK_HINGE_CONSTRAINT_CONSTRUCT {}

bhkHingeConstraint::~bhkHingeConstraint() {}

void bhkHingeConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkHingeConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkHingeConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkHingeConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkHingeConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkHingeConstraint::GetType() const {
	return TYPE;
};
