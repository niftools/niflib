/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBinaryExtraData.h"
#include "../../include/gen/ByteArray.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBinaryExtraData::TYPE("NiBinaryExtraData", &NI_BINARY_EXTRA_DATA_PARENT::TypeConst() );

NiBinaryExtraData::NiBinaryExtraData() NI_BINARY_EXTRA_DATA_CONSTRUCT {}

NiBinaryExtraData::~NiBinaryExtraData() {}

void NiBinaryExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBinaryExtraData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBinaryExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBinaryExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBinaryExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBinaryExtraData::GetType() const {
	return TYPE;
};


vector<byte> NiBinaryExtraData::GetData() const {
	return binaryData.data;
};

void NiBinaryExtraData::SetData( const vector<byte> & n ) {
	binaryData.dataSize = uint(n.size());
	binaryData.data = n;
};