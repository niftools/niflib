/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkStiffSpringConstraint.h"

//Definition of TYPE constant
const Type bhkStiffSpringConstraint::TYPE("bhkStiffSpringConstraint", &BHK_STIFF_SPRING_CONSTRAINT_PARENT::TypeConst() );

bhkStiffSpringConstraint::bhkStiffSpringConstraint() BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT {}

bhkStiffSpringConstraint::~bhkStiffSpringConstraint() {}

void bhkStiffSpringConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_STIFF_SPRING_CONSTRAINT_READ
}

void bhkStiffSpringConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_STIFF_SPRING_CONSTRAINT_WRITE
}

string bhkStiffSpringConstraint::asString( bool verbose ) const {
	BHK_STIFF_SPRING_CONSTRAINT_STRING
}

void bhkStiffSpringConstraint::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_STIFF_SPRING_CONSTRAINT_FIXLINKS
}

list<NiObjectRef> bhkStiffSpringConstraint::GetRefs() const {
	BHK_STIFF_SPRING_CONSTRAINT_GETREFS
}

const Type & bhkStiffSpringConstraint::GetType() const {
	return TYPE;
};

