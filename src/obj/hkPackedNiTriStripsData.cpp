/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/hkPackedNiTriStripsData.h"
#include "../../include/gen/hkTriangle.h"
using namespace Niflib;

//Definition of TYPE constant
const Type hkPackedNiTriStripsData::TYPE("hkPackedNiTriStripsData", &HK_PACKED_NI_TRI_STRIPS_DATA_PARENT::TypeConst() );

hkPackedNiTriStripsData::hkPackedNiTriStripsData() HK_PACKED_NI_TRI_STRIPS_DATA_CONSTRUCT {}

hkPackedNiTriStripsData::~hkPackedNiTriStripsData() {}

void hkPackedNiTriStripsData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void hkPackedNiTriStripsData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string hkPackedNiTriStripsData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void hkPackedNiTriStripsData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> hkPackedNiTriStripsData::GetRefs() const {
	return InternalGetRefs();
}

const Type & hkPackedNiTriStripsData::GetType() const {
	return TYPE;
};

