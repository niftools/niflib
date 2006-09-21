/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineBasisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineBasisData::TYPE("NiBSplineBasisData", &NI_B_SPLINE_BASIS_DATA_PARENT::TypeConst() );

NiBSplineBasisData::NiBSplineBasisData() NI_B_SPLINE_BASIS_DATA_CONSTRUCT {}

NiBSplineBasisData::~NiBSplineBasisData() {}

void NiBSplineBasisData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_SPLINE_BASIS_DATA_READ
}

void NiBSplineBasisData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_B_SPLINE_BASIS_DATA_WRITE
}

string NiBSplineBasisData::asString( bool verbose ) const {
	NI_B_SPLINE_BASIS_DATA_STRING
}

void NiBSplineBasisData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_SPLINE_BASIS_DATA_FIXLINKS
}

list<NiObjectRef> NiBSplineBasisData::GetRefs() const {
	NI_B_SPLINE_BASIS_DATA_GETREFS
}

const Type & NiBSplineBasisData::GetType() const {
	return TYPE;
};

uint NiBSplineBasisData::GetNumControlPt() const {
	return numControlPt;
}

void NiBSplineBasisData::SetNumControlPt( uint value ) {
	numControlPt = value;
}

