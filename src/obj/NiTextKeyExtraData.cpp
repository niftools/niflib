/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextKeyExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextKeyExtraData::TYPE("NiTextKeyExtraData", &NI_TEXT_KEY_EXTRA_DATA_PARENT::TypeConst() );

NiTextKeyExtraData::NiTextKeyExtraData() NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT {}

NiTextKeyExtraData::~NiTextKeyExtraData() {}

void NiTextKeyExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTextKeyExtraData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTextKeyExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextKeyExtraData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTextKeyExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextKeyExtraData::GetType() const {
	return TYPE;
};

vector< Key<string> > NiTextKeyExtraData::GetKeys() const {
	return textKeys;
}

void NiTextKeyExtraData::SetKeys( vector< Key<string> > const & keys ) {
	textKeys = keys;
}

