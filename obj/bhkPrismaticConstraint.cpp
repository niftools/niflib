/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkPrismaticConstraint.h"

//Definition of TYPE constant
const Type bhkPrismaticConstraint::TYPE("bhkPrismaticConstraint", &BHK_PRISMATIC_CONSTRAINT_PARENT::TYPE );

bhkPrismaticConstraint::bhkPrismaticConstraint() BHK_PRISMATIC_CONSTRAINT_CONSTRUCT {}

bhkPrismaticConstraint::~bhkPrismaticConstraint() {}

void bhkPrismaticConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_PRISMATIC_CONSTRAINT_READ
}

void bhkPrismaticConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_PRISMATIC_CONSTRAINT_WRITE
}

string bhkPrismaticConstraint::asString( bool verbose ) const {
	BHK_PRISMATIC_CONSTRAINT_STRING
}

void bhkPrismaticConstraint::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_PRISMATIC_CONSTRAINT_FIXLINKS
}

list<NiObjectRef> bhkPrismaticConstraint::GetRefs() const {
	BHK_PRISMATIC_CONSTRAINT_GETREFS
}

const Type & bhkPrismaticConstraint::GetType() const {
	return TYPE;
};

