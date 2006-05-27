/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPoint3Interpolator.h"
#include "NiPosData.h"

//Definition of TYPE constant
const Type NiPoint3Interpolator::TYPE("NiPoint3Interpolator", &NI_POINT3_INTERPOLATOR_PARENT::TYPE );

NiPoint3Interpolator::NiPoint3Interpolator() NI_POINT3_INTERPOLATOR_CONSTRUCT {}

NiPoint3Interpolator::~NiPoint3Interpolator() {}

void NiPoint3Interpolator::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_POINT3_INTERPOLATOR_READ
}

void NiPoint3Interpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_POINT3_INTERPOLATOR_WRITE
}

string NiPoint3Interpolator::asString( bool verbose ) const {
	NI_POINT3_INTERPOLATOR_STRING
}

void NiPoint3Interpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_POINT3_INTERPOLATOR_FIXLINKS
}

