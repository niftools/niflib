/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFloatData.h"
#include "../gen/KeyGroup.h"

//Definition of TYPE constant
const Type NiFloatData::TYPE("NiFloatData", &NI_FLOAT_DATA_PARENT::TypeConst() );

NiFloatData::NiFloatData() NI_FLOAT_DATA_CONSTRUCT {}

NiFloatData::~NiFloatData() {}

void NiFloatData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOAT_DATA_READ
}

void NiFloatData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_FLOAT_DATA_WRITE
}

string NiFloatData::asString( bool verbose ) const {
	NI_FLOAT_DATA_STRING
}

void NiFloatData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLOAT_DATA_FIXLINKS
}

list<NiObjectRef> NiFloatData::GetRefs() const {
	NI_FLOAT_DATA_GETREFS
}

const Type & NiFloatData::GetType() const {
	return TYPE;
};

KeyType NiFloatData::GetKeyType() const {
	return data.interpolation;
}

void NiFloatData::SetKeyType( KeyType t ) {
	data.interpolation = t;
}

vector< Key<float> > NiFloatData::GetKeys() const {
	return data.keys;
}

void NiFloatData::SetKeys( vector< Key<float> > const & keys ) {
	data.keys = keys;
}


