/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiKeyframeData.h"
#include "gen/KeyGroup.h"
#include "gen/KeyGroup.h"
#include "gen/KeyGroup.h"

//Definition of TYPE constant
const Type NiKeyframeData::TYPE("NiKeyframeData", &NI_KEYFRAME_DATA_PARENT::TYPE );

NiKeyframeData::NiKeyframeData() NI_KEYFRAME_DATA_CONSTRUCT {}

NiKeyframeData::~NiKeyframeData() {}

void NiKeyframeData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_KEYFRAME_DATA_READ
}

void NiKeyframeData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_KEYFRAME_DATA_WRITE
}

string NiKeyframeData::asString( bool verbose ) const {
	NI_KEYFRAME_DATA_STRING
}

void NiKeyframeData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_KEYFRAME_DATA_FIXLINKS
}

const Type & NiKeyframeData::GetType() const {
	return TYPE;
};

