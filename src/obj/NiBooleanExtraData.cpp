/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBooleanExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBooleanExtraData::TYPE("NiBooleanExtraData", &NI_BOOLEAN_EXTRA_DATA_PARENT::TypeConst() );

NiBooleanExtraData::NiBooleanExtraData() NI_BOOLEAN_EXTRA_DATA_CONSTRUCT {}

NiBooleanExtraData::~NiBooleanExtraData() {}

void NiBooleanExtraData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBooleanExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBooleanExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBooleanExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBooleanExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBooleanExtraData::GetType() const {
	return TYPE;
};

bool NiBooleanExtraData::GetData() const {
	return (booleanData != 0);
}

void NiBooleanExtraData::SetData( bool n ) {
	booleanData = n;
}
