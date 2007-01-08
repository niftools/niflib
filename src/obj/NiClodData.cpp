/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiClodData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiClodData::TYPE("NiClodData", &NI_CLOD_DATA_PARENT::TypeConst() );

NiClodData::NiClodData() NI_CLOD_DATA_CONSTRUCT {}

NiClodData::~NiClodData() {}

void NiClodData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiClodData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiClodData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiClodData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiClodData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiClodData::GetType() const {
	return TYPE;
};

