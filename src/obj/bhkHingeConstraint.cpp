/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkHingeConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkHingeConstraint::TYPE("bhkHingeConstraint", &BHK_HINGE_CONSTRAINT_PARENT::TypeConst() );

bhkHingeConstraint::bhkHingeConstraint() BHK_HINGE_CONSTRAINT_CONSTRUCT {}

bhkHingeConstraint::~bhkHingeConstraint() {}

void bhkHingeConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkHingeConstraint::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkHingeConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkHingeConstraint::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkHingeConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkHingeConstraint::GetType() const {
	return TYPE;
};

