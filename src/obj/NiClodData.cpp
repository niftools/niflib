/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiClodData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiClodData::TYPE("NiClodData", &NI_CLOD_DATA_PARENT::TypeConst() );

NiClodData::NiClodData() NI_CLOD_DATA_CONSTRUCT {}

NiClodData::~NiClodData() {}

void NiClodData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CLOD_DATA_READ
}

void NiClodData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_CLOD_DATA_WRITE
}

string NiClodData::asString( bool verbose ) const {
	NI_CLOD_DATA_STRING
}

void NiClodData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CLOD_DATA_FIXLINKS
}

list<NiObjectRef> NiClodData::GetRefs() const {
	NI_CLOD_DATA_GETREFS
}

const Type & NiClodData::GetType() const {
	return TYPE;
};

