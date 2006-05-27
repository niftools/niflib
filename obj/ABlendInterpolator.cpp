/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "ABlendInterpolator.h"

//Definition of TYPE constant
const Type ABlendInterpolator::TYPE("ABlendInterpolator", &A_BLEND_INTERPOLATOR_PARENT::TYPE );

ABlendInterpolator::ABlendInterpolator() A_BLEND_INTERPOLATOR_CONSTRUCT {}

ABlendInterpolator::~ABlendInterpolator() {}

void ABlendInterpolator::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	A_BLEND_INTERPOLATOR_READ
}

void ABlendInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_BLEND_INTERPOLATOR_WRITE
}

string ABlendInterpolator::asString( bool verbose ) const {
	A_BLEND_INTERPOLATOR_STRING
}

void ABlendInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	A_BLEND_INTERPOLATOR_FIXLINKS
}

