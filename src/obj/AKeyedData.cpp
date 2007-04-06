/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AKeyedData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AKeyedData::TYPE("AKeyedData", &A_KEYED_DATA_PARENT::TypeConst() );

AKeyedData::AKeyedData() A_KEYED_DATA_CONSTRUCT {}

AKeyedData::~AKeyedData() {}

void AKeyedData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void AKeyedData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string AKeyedData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AKeyedData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> AKeyedData::GetRefs() const {
	return InternalGetRefs();
}

const Type & AKeyedData::GetType() const {
	return TYPE;
};

const Type & AKeyedData::TypeConst() {
	return TYPE;
}
