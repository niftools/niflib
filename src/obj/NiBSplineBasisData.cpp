/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineBasisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineBasisData::TYPE("NiBSplineBasisData", &NI_B_SPLINE_BASIS_DATA_PARENT::TypeConst() );

NiBSplineBasisData::NiBSplineBasisData() NI_B_SPLINE_BASIS_DATA_CONSTRUCT {}

NiBSplineBasisData::~NiBSplineBasisData() {}

void NiBSplineBasisData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSplineBasisData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSplineBasisData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineBasisData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSplineBasisData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineBasisData::GetType() const {
	return TYPE;
};

unsigned int NiBSplineBasisData::GetNumControlPt() const {
	return numControlPt;
}

void NiBSplineBasisData::SetNumControlPt( unsigned int value ) {
	numControlPt = value;
}

const Type & NiBSplineBasisData::TypeConst() {
	return TYPE;
}
