/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBoolTimelineInterpolator.h"
#include "NiBoolData.h"

//Definition of TYPE constant
const Type NiBoolTimelineInterpolator::TYPE("NiBoolTimelineInterpolator", &NI_BOOL_TIMELINE_INTERPOLATOR_PARENT::TYPE );

NiBoolTimelineInterpolator::NiBoolTimelineInterpolator() NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT {}

NiBoolTimelineInterpolator::~NiBoolTimelineInterpolator() {}

void NiBoolTimelineInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BOOL_TIMELINE_INTERPOLATOR_READ
}

void NiBoolTimelineInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BOOL_TIMELINE_INTERPOLATOR_WRITE
}

string NiBoolTimelineInterpolator::asString( bool verbose ) const {
	NI_BOOL_TIMELINE_INTERPOLATOR_STRING
}

void NiBoolTimelineInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BOOL_TIMELINE_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBoolTimelineInterpolator::GetRefs() const {
	NI_BOOL_TIMELINE_INTERPOLATOR_GETREFS
}

const Type & NiBoolTimelineInterpolator::GetType() const {
	return TYPE;
};

