/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "AInterpolator.h"

//Definition of TYPE constant
const Type AInterpolator::TYPE("AInterpolator", &A_INTERPOLATOR_PARENT::TYPE );

AInterpolator::AInterpolator() A_INTERPOLATOR_CONSTRUCT {}

AInterpolator::~AInterpolator() {}

void AInterpolator::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	A_INTERPOLATOR_READ
}

void AInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_INTERPOLATOR_WRITE
}

string AInterpolator::asString( bool verbose ) const {
	A_INTERPOLATOR_STRING
}

void AInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	A_INTERPOLATOR_FIXLINKS
}

