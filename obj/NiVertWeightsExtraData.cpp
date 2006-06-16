/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiVertWeightsExtraData.h"

//Definition of TYPE constant
const Type NiVertWeightsExtraData::TYPE("NiVertWeightsExtraData", &NI_VERT_WEIGHTS_EXTRA_DATA_PARENT::TypeConst() );

NiVertWeightsExtraData::NiVertWeightsExtraData() NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT {}

NiVertWeightsExtraData::~NiVertWeightsExtraData() {}

void NiVertWeightsExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VERT_WEIGHTS_EXTRA_DATA_READ
}

void NiVertWeightsExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_VERT_WEIGHTS_EXTRA_DATA_WRITE
}

string NiVertWeightsExtraData::asString( bool verbose ) const {
	NI_VERT_WEIGHTS_EXTRA_DATA_STRING
}

void NiVertWeightsExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VERT_WEIGHTS_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiVertWeightsExtraData::GetRefs() const {
	NI_VERT_WEIGHTS_EXTRA_DATA_GETREFS
}

const Type & NiVertWeightsExtraData::GetType() const {
	return TYPE;
};

