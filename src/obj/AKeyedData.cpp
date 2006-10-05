/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AKeyedData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AKeyedData::TYPE("AKeyedData", &A_KEYED_DATA_PARENT::TypeConst() );

AKeyedData::AKeyedData() A_KEYED_DATA_CONSTRUCT {}

AKeyedData::~AKeyedData() {}

void AKeyedData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void AKeyedData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string AKeyedData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AKeyedData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> AKeyedData::GetRefs() const {
	return InternalGetRefs();
}

const Type & AKeyedData::GetType() const {
	return TYPE;
};

