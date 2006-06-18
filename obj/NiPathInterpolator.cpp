/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPathInterpolator.h"
#include "NiPosData.h"
#include "NiFloatData.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiPathInterpolator::TYPE("NiPathInterpolator", &NI_PATH_INTERPOLATOR_PARENT::TypeConst() );

NiPathInterpolator::NiPathInterpolator() NI_PATH_INTERPOLATOR_CONSTRUCT {}

NiPathInterpolator::~NiPathInterpolator() {}

void NiPathInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PATH_INTERPOLATOR_READ
}

void NiPathInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PATH_INTERPOLATOR_WRITE
}

string NiPathInterpolator::asString( bool verbose ) const {
	NI_PATH_INTERPOLATOR_STRING
}

void NiPathInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PATH_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiPathInterpolator::GetRefs() const {
	NI_PATH_INTERPOLATOR_GETREFS
}

const Type & NiPathInterpolator::GetType() const {
	return TYPE;
};

