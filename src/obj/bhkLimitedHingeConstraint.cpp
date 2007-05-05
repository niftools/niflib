/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkLimitedHingeConstraint.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkLimitedHingeConstraint::TYPE("bhkLimitedHingeConstraint", &BHK_LIMITED_HINGE_CONSTRAINT_PARENT::TYPE );

bhkLimitedHingeConstraint::bhkLimitedHingeConstraint() BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT {}

bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint() {}

void bhkLimitedHingeConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkLimitedHingeConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkLimitedHingeConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkLimitedHingeConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkLimitedHingeConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkLimitedHingeConstraint::GetType() const {
	return TYPE;
};
