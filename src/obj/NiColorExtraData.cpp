/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiColorExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiColorExtraData::TYPE("NiColorExtraData", &NI_COLOR_EXTRA_DATA_PARENT::TYPE );

NiColorExtraData::NiColorExtraData() NI_COLOR_EXTRA_DATA_CONSTRUCT {}

NiColorExtraData::~NiColorExtraData() {}

void NiColorExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiColorExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiColorExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiColorExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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
