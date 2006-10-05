/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVectorExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVectorExtraData::TYPE("NiVectorExtraData", &NI_VECTOR_EXTRA_DATA_PARENT::TypeConst() );

NiVectorExtraData::NiVectorExtraData() NI_VECTOR_EXTRA_DATA_CONSTRUCT {}

NiVectorExtraData::~NiVectorExtraData() {}

void NiVectorExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiVectorExtraData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiVectorExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVectorExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiVectorExtraData::GetRefs() const {
	return InternalGetRefs();
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

