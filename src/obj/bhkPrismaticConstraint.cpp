/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkPrismaticConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPrismaticConstraint::TYPE("bhkPrismaticConstraint", &BHK_PRISMATIC_CONSTRAINT_PARENT::TypeConst() );

bhkPrismaticConstraint::bhkPrismaticConstraint() BHK_PRISMATIC_CONSTRAINT_CONSTRUCT {}

bhkPrismaticConstraint::~bhkPrismaticConstraint() {}

void bhkPrismaticConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkPrismaticConstraint::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkPrismaticConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkPrismaticConstraint::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkPrismaticConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkPrismaticConstraint::GetType() const {
	return TYPE;
};

