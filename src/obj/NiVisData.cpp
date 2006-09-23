/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVisData::TYPE("NiVisData", &NI_VIS_DATA_PARENT::TypeConst() );

NiVisData::NiVisData() NI_VIS_DATA_CONSTRUCT {}

NiVisData::~NiVisData() {}

void NiVisData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiVisData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiVisData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVisData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiVisData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVisData::GetType() const {
	return TYPE;
};

