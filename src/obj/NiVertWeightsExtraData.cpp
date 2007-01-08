/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVertWeightsExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVertWeightsExtraData::TYPE("NiVertWeightsExtraData", &NI_VERT_WEIGHTS_EXTRA_DATA_PARENT::TypeConst() );

NiVertWeightsExtraData::NiVertWeightsExtraData() NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT {}

NiVertWeightsExtraData::~NiVertWeightsExtraData() {}

void NiVertWeightsExtraData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiVertWeightsExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiVertWeightsExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVertWeightsExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiVertWeightsExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVertWeightsExtraData::GetType() const {
	return TYPE;
};

vector<float> NiVertWeightsExtraData::GetData() const {
	return weight;
}
	
void NiVertWeightsExtraData::SetData( const vector<float> & n ) {
	numVertices = unsigned int(n.size());
	numBytes = numVertices + 2;
	weight = n;
}
