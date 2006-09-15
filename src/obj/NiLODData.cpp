/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLODData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLODData::TYPE("NiLODData", &NI_L_O_D_DATA_PARENT::TypeConst() );

NiLODData::NiLODData() NI_L_O_D_DATA_CONSTRUCT {}

NiLODData::~NiLODData() {}

void NiLODData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_L_O_D_DATA_READ
}

void NiLODData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_L_O_D_DATA_WRITE
}

string NiLODData::asString( bool verbose ) const {
	NI_L_O_D_DATA_STRING
}

void NiLODData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_L_O_D_DATA_FIXLINKS
}

list<NiObjectRef> NiLODData::GetRefs() const {
	NI_L_O_D_DATA_GETREFS
}

const Type & NiLODData::GetType() const {
	return TYPE;
};

