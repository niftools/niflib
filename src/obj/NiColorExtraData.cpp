/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiColorExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiColorExtraData::TYPE("NiColorExtraData", &NI_COLOR_EXTRA_DATA_PARENT::TypeConst() );

NiColorExtraData::NiColorExtraData() NI_COLOR_EXTRA_DATA_CONSTRUCT {}

NiColorExtraData::~NiColorExtraData() {}

void NiColorExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiColorExtraData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiColorExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiColorExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiColorExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiColorExtraData::GetType() const {
	return TYPE;
};

Color4 NiColorExtraData::GetData() const {
	return data;
}
	
void NiColorExtraData::SetData( const Color4 & n ) {
	data = n;
}
