/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiVectorExtraData.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiVectorExtraData::TYPE("NiVectorExtraData", &NI_VECTOR_EXTRA_DATA_PARENT::TypeConst() );

NiVectorExtraData::NiVectorExtraData() NI_VECTOR_EXTRA_DATA_CONSTRUCT {}

NiVectorExtraData::~NiVectorExtraData() {}

void NiVectorExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VECTOR_EXTRA_DATA_READ
}

void NiVectorExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_VECTOR_EXTRA_DATA_WRITE
}

string NiVectorExtraData::asString( bool verbose ) const {
	NI_VECTOR_EXTRA_DATA_STRING
}

void NiVectorExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VECTOR_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiVectorExtraData::GetRefs() const {
	NI_VECTOR_EXTRA_DATA_GETREFS
}

const Type & NiVectorExtraData::GetType() const {
	return TYPE;
};

Vector3 NiVectorExtraData::GetData() const {
	return vectorData;
};
	
void NiVectorExtraData::SetData( const Vector3 & n ) {
	vectorData = n;
};

