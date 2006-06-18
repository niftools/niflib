/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFloatInterpolator.h"
#include "NiFloatData.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiFloatInterpolator::TYPE("NiFloatInterpolator", &NI_FLOAT_INTERPOLATOR_PARENT::TypeConst() );

NiFloatInterpolator::NiFloatInterpolator() NI_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiFloatInterpolator::~NiFloatInterpolator() {}

void NiFloatInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOAT_INTERPOLATOR_READ
}

void NiFloatInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_FLOAT_INTERPOLATOR_WRITE
}

string NiFloatInterpolator::asString( bool verbose ) const {
	NI_FLOAT_INTERPOLATOR_STRING
}

void NiFloatInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOAT_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiFloatInterpolator::GetRefs() const {
	NI_FLOAT_INTERPOLATOR_GETREFS
}

const Type & NiFloatInterpolator::GetType() const {
	return TYPE;
};

