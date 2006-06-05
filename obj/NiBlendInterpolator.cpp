/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBlendInterpolator.h"

//Definition of TYPE constant
const Type NiBlendInterpolator::TYPE("NiBlendInterpolator", &NI_BLEND_INTERPOLATOR_PARENT::TYPE );

NiBlendInterpolator::NiBlendInterpolator() NI_BLEND_INTERPOLATOR_CONSTRUCT {}

NiBlendInterpolator::~NiBlendInterpolator() {}

void NiBlendInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BLEND_INTERPOLATOR_READ
}

void NiBlendInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BLEND_INTERPOLATOR_WRITE
}

string NiBlendInterpolator::asString( bool verbose ) const {
	NI_BLEND_INTERPOLATOR_STRING
}

void NiBlendInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BLEND_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBlendInterpolator::GetRefs() const {
	NI_BLEND_INTERPOLATOR_GETREFS
}

const Type & NiBlendInterpolator::GetType() const {
	return TYPE;
};

