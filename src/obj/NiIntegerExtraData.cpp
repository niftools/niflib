/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiIntegerExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiIntegerExtraData::TYPE("NiIntegerExtraData", &NI_INTEGER_EXTRA_DATA_PARENT::TYPE );

NiIntegerExtraData::NiIntegerExtraData() NI_INTEGER_EXTRA_DATA_CONSTRUCT {}

NiIntegerExtraData::~NiIntegerExtraData() {}

void NiIntegerExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiIntegerExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiIntegerExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiIntegerExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiIntegerExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiIntegerExtraData::GetType() const {
	return TYPE;
};

unsigned int NiIntegerExtraData::GetData() const {
	return integerData;
}
	
void NiIntegerExtraData::SetData( unsigned int n ) {
	integerData = n;
}
