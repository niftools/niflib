/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBoolInterpolator.h"
#include "NiBoolData.h"

//Definition of TYPE constant
const Type NiBoolInterpolator::TYPE("NiBoolInterpolator", &NI_BOOL_INTERPOLATOR_PARENT::TYPE );

NiBoolInterpolator::NiBoolInterpolator() NI_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBoolInterpolator::~NiBoolInterpolator() {}

void NiBoolInterpolator::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_BOOL_INTERPOLATOR_READ
}

void NiBoolInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_BOOL_INTERPOLATOR_WRITE
}

string NiBoolInterpolator::asString( bool verbose ) const {
	NI_BOOL_INTERPOLATOR_STRING
}

void NiBoolInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_BOOL_INTERPOLATOR_FIXLINKS
}

