/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineBasisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineBasisData::TYPE("NiBSplineBasisData", &NI_B_SPLINE_BASIS_DATA_PARENT::TypeConst() );

NiBSplineBasisData::NiBSplineBasisData() NI_B_SPLINE_BASIS_DATA_CONSTRUCT {}

NiBSplineBasisData::~NiBSplineBasisData() {}

void NiBSplineBasisData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBSplineBasisData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBSplineBasisData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineBasisData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBSplineBasisData::GetRefs() const {
	return InternalGetRefs();
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

