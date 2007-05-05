/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiIntegersExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiIntegersExtraData::TYPE("NiIntegersExtraData", &NI_INTEGERS_EXTRA_DATA_PARENT::TYPE );

NiIntegersExtraData::NiIntegersExtraData() NI_INTEGERS_EXTRA_DATA_CONSTRUCT {}

NiIntegersExtraData::~NiIntegersExtraData() {}

void NiIntegersExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiIntegersExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiIntegersExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiIntegersExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiIntegersExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiIntegersExtraData::GetType() const {
	return TYPE;
};

vector<unsigned int> NiIntegersExtraData::GetData() const {
	return data;
};
	
void NiIntegersExtraData::SetData( const vector<unsigned int> & n ) {
	numIntegers = (unsigned int)( n.size() );
	data = n;
};
