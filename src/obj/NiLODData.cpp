/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLODData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLODData::TYPE("NiLODData", &NI_L_O_D_DATA_PARENT::TypeConst() );

NiLODData::NiLODData() NI_L_O_D_DATA_CONSTRUCT {}

NiLODData::~NiLODData() {}

void NiLODData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiLODData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiLODData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLODData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiLODData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLODData::GetType() const {
	return TYPE;
};

const Type & NiLODData::TypeConst() {
	return TYPE;
}
