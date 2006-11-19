/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkLimitedHingeConstraint.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkLimitedHingeConstraint::TYPE("bhkLimitedHingeConstraint", &BHK_LIMITED_HINGE_CONSTRAINT_PARENT::TypeConst() );

bhkLimitedHingeConstraint::bhkLimitedHingeConstraint() BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT {}

bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint() {}

void bhkLimitedHingeConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkLimitedHingeConstraint::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkLimitedHingeConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkLimitedHingeConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkLimitedHingeConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkLimitedHingeConstraint::GetType() const {
	return TYPE;
};

