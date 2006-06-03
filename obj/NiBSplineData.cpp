/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBSplineData.h"

//Definition of TYPE constant
const Type NiBSplineData::TYPE("NiBSplineData", &NI_B_SPLINE_DATA_PARENT::TYPE );

NiBSplineData::NiBSplineData() NI_B_SPLINE_DATA_CONSTRUCT {}

NiBSplineData::~NiBSplineData() {}

void NiBSplineData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_B_SPLINE_DATA_READ
}

void NiBSplineData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_B_SPLINE_DATA_WRITE
}

string NiBSplineData::asString( bool verbose ) const {
	NI_B_SPLINE_DATA_STRING
}

void NiBSplineData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_B_SPLINE_DATA_FIXLINKS
}

const Type & NiBSplineData::GetType() const {
	return TYPE;
};

