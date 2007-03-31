/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkMalleableConstraint.h"
#include "../../include/gen/RagDollDescriptor.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMalleableConstraint::TYPE("bhkMalleableConstraint", &BHK_MALLEABLE_CONSTRAINT_PARENT::TypeConst() );

bhkMalleableConstraint::bhkMalleableConstraint() BHK_MALLEABLE_CONSTRAINT_CONSTRUCT {}

bhkMalleableConstraint::~bhkMalleableConstraint() {}

void bhkMalleableConstraint::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkMalleableConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkMalleableConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkMalleableConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkMalleableConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkMalleableConstraint::GetType() const {
	return TYPE;
};

const Type & bhkMalleableConstraint::TypeConst() {
	return TYPE;
}
