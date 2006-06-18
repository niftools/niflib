/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTextKeyExtraData.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiTextKeyExtraData::TYPE("NiTextKeyExtraData", &NI_TEXT_KEY_EXTRA_DATA_PARENT::TypeConst() );

NiTextKeyExtraData::NiTextKeyExtraData() NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT {}

NiTextKeyExtraData::~NiTextKeyExtraData() {}

void NiTextKeyExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXT_KEY_EXTRA_DATA_READ
}

void NiTextKeyExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TEXT_KEY_EXTRA_DATA_WRITE
}

string NiTextKeyExtraData::asString( bool verbose ) const {
	NI_TEXT_KEY_EXTRA_DATA_STRING
}

void NiTextKeyExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXT_KEY_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiTextKeyExtraData::GetRefs() const {
	NI_TEXT_KEY_EXTRA_DATA_GETREFS
}

const Type & NiTextKeyExtraData::GetType() const {
	return TYPE;
};

vector< Key<string> > NiTextKeyExtraData::GetKeys() const {
	return textKeys;
}

void NiTextKeyExtraData::SetKeys( vector< Key<string> > const & keys ) {
	textKeys = keys;
}

