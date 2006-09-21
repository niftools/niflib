/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBooleanExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBooleanExtraData::TYPE("NiBooleanExtraData", &NI_BOOLEAN_EXTRA_DATA_PARENT::TypeConst() );

NiBooleanExtraData::NiBooleanExtraData() NI_BOOLEAN_EXTRA_DATA_CONSTRUCT {}

NiBooleanExtraData::~NiBooleanExtraData() {}

void NiBooleanExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BOOLEAN_EXTRA_DATA_READ
}

void NiBooleanExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BOOLEAN_EXTRA_DATA_WRITE
}

string NiBooleanExtraData::asString( bool verbose ) const {
	NI_BOOLEAN_EXTRA_DATA_STRING
}

void NiBooleanExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BOOLEAN_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiBooleanExtraData::GetRefs() const {
	NI_BOOLEAN_EXTRA_DATA_GETREFS
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