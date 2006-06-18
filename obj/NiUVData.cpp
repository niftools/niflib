/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiUVData.h"
#include "../gen/KeyGroup.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiUVData::TYPE("NiUVData", &NI_U_V_DATA_PARENT::TypeConst() );

NiUVData::NiUVData() NI_U_V_DATA_CONSTRUCT {}

NiUVData::~NiUVData() {}

void NiUVData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_U_V_DATA_READ
}

void NiUVData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_U_V_DATA_WRITE
}

string NiUVData::asString( bool verbose ) const {
	NI_U_V_DATA_STRING
}

void NiUVData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_U_V_DATA_FIXLINKS
}

list<NiObjectRef> NiUVData::GetRefs() const {
	NI_U_V_DATA_GETREFS
}

const Type & NiUVData::GetType() const {
	return TYPE;
};

