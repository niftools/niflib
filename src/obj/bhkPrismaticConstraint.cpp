/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkPrismaticConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPrismaticConstraint::TYPE("bhkPrismaticConstraint", &BHK_PRISMATIC_CONSTRAINT_PARENT::TYPE );

bhkPrismaticConstraint::bhkPrismaticConstraint() BHK_PRISMATIC_CONSTRAINT_CONSTRUCT {}

bhkPrismaticConstraint::~bhkPrismaticConstraint() {}

void bhkPrismaticConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkPrismaticConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkPrismaticConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkPrismaticConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkPrismaticConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkPrismaticConstraint::GetType() const {
	return TYPE;
};
