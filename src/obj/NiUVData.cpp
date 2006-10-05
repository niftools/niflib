/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiUVData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiUVData::TYPE("NiUVData", &NI_U_V_DATA_PARENT::TypeConst() );

NiUVData::NiUVData() NI_U_V_DATA_CONSTRUCT {}

NiUVData::~NiUVData() {}

void NiUVData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiUVData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiUVData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiUVData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiUVData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiUVData::GetType() const {
	return TYPE;
};

