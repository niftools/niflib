/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPosData.h"
#include "gen/KeyGroup.h"

//Definition of TYPE constant
const Type NiPosData::TYPE("NiPosData", &NI_POS_DATA_PARENT::TYPE );

NiPosData::NiPosData() NI_POS_DATA_CONSTRUCT {}

NiPosData::~NiPosData() {}

void NiPosData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_POS_DATA_READ
}

void NiPosData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_POS_DATA_WRITE
}

string NiPosData::asString( bool verbose ) const {
	NI_POS_DATA_STRING
}

void NiPosData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_POS_DATA_FIXLINKS
}

list<NiObjectRef> NiPosData::GetRefs() const {
	NI_POS_DATA_GETREFS
}

const Type & NiPosData::GetType() const {
	return TYPE;
};

