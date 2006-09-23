/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTransformData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformData::TYPE("NiTransformData", &NI_TRANSFORM_DATA_PARENT::TypeConst() );

NiTransformData::NiTransformData() NI_TRANSFORM_DATA_CONSTRUCT {}

NiTransformData::~NiTransformData() {}

void NiTransformData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTransformData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTransformData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTransformData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTransformData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTransformData::GetType() const {
	return TYPE;
};

