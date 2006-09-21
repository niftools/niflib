/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiIntegersExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiIntegersExtraData::TYPE("NiIntegersExtraData", &NI_INTEGERS_EXTRA_DATA_PARENT::TypeConst() );

NiIntegersExtraData::NiIntegersExtraData() NI_INTEGERS_EXTRA_DATA_CONSTRUCT {}

NiIntegersExtraData::~NiIntegersExtraData() {}

void NiIntegersExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_INTEGERS_EXTRA_DATA_READ
}

void NiIntegersExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_INTEGERS_EXTRA_DATA_WRITE
}

string NiIntegersExtraData::asString( bool verbose ) const {
	NI_INTEGERS_EXTRA_DATA_STRING
}

void NiIntegersExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_INTEGERS_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiIntegersExtraData::GetRefs() const {
	NI_INTEGERS_EXTRA_DATA_GETREFS
}

const Type & NiIntegersExtraData::GetType() const {
	return TYPE;
};

vector<uint> NiIntegersExtraData::GetData() const {
	return data;
};
	
void NiIntegersExtraData::SetData( const vector<uint> & n ) {
	numIntegers = uint( n.size() );
	data = n;
};