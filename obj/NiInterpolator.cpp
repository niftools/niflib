/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiInterpolator.h"

//Definition of TYPE constant
const Type NiInterpolator::TYPE("NiInterpolator", &NI_INTERPOLATOR_PARENT::TYPE );

NiInterpolator::NiInterpolator() NI_INTERPOLATOR_CONSTRUCT {}

NiInterpolator::~NiInterpolator() {}

void NiInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_INTERPOLATOR_READ
}

void NiInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_INTERPOLATOR_WRITE
}

string NiInterpolator::asString( bool verbose ) const {
	NI_INTERPOLATOR_STRING
}

void NiInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiInterpolator::GetRefs() const {
	NI_INTERPOLATOR_GETREFS
}

const Type & NiInterpolator::GetType() const {
	return TYPE;
};

