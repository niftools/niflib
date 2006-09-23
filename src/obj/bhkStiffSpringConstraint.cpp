/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkStiffSpringConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkStiffSpringConstraint::TYPE("bhkStiffSpringConstraint", &BHK_STIFF_SPRING_CONSTRAINT_PARENT::TypeConst() );

bhkStiffSpringConstraint::bhkStiffSpringConstraint() BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT {}

bhkStiffSpringConstraint::~bhkStiffSpringConstraint() {}

void bhkStiffSpringConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkStiffSpringConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkStiffSpringConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkStiffSpringConstraint::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkStiffSpringConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkStiffSpringConstraint::GetType() const {
	return TYPE;
};

