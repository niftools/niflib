/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/APSysData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type APSysData::TYPE("APSysData", &A_P_SYS_DATA_PARENT::TypeConst() );

APSysData::APSysData() A_P_SYS_DATA_CONSTRUCT {}

APSysData::~APSysData() {}

void APSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void APSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string APSysData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void APSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> APSysData::GetRefs() const {
	return InternalGetRefs();
}

const Type & APSysData::GetType() const {
	return TYPE;
};

const Type & APSysData::TypeConst() {
	return TYPE;
}
