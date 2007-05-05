/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiUVData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiUVData::TYPE("NiUVData", &NI_U_V_DATA_PARENT::TYPE );

NiUVData::NiUVData() NI_U_V_DATA_CONSTRUCT {}

NiUVData::~NiUVData() {}

void NiUVData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiUVData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiUVData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiUVData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiUVData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiUVData::GetType() const {
	return TYPE;
};
