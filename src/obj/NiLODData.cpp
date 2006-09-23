/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLODData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLODData::TYPE("NiLODData", &NI_L_O_D_DATA_PARENT::TypeConst() );

NiLODData::NiLODData() NI_L_O_D_DATA_CONSTRUCT {}

NiLODData::~NiLODData() {}

void NiLODData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiLODData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiLODData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLODData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiLODData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLODData::GetType() const {
	return TYPE;
};

