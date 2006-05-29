/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkLimitedHingeConstraint.h"

//Definition of TYPE constant
const Type bhkLimitedHingeConstraint::TYPE("bhkLimitedHingeConstraint", &BHK_LIMITED_HINGE_CONSTRAINT_PARENT::TYPE );

bhkLimitedHingeConstraint::bhkLimitedHingeConstraint() BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT {}

bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint() {}

void bhkLimitedHingeConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  BHK_LIMITED_HINGE_CONSTRAINT_READ
}

void bhkLimitedHingeConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  BHK_LIMITED_HINGE_CONSTRAINT_WRITE
}

string bhkLimitedHingeConstraint::asString( bool verbose ) const {
  BHK_LIMITED_HINGE_CONSTRAINT_STRING
}

void bhkLimitedHingeConstraint::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  BHK_LIMITED_HINGE_CONSTRAINT_FIXLINKS
}

const Type & bhkLimitedHingeConstraint::GetType() const {
  return TYPE;
};

