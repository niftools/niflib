/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextKeyExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextKeyExtraData::TYPE("NiTextKeyExtraData", &NI_TEXT_KEY_EXTRA_DATA_PARENT::TypeConst() );

NiTextKeyExtraData::NiTextKeyExtraData() NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT {}

NiTextKeyExtraData::~NiTextKeyExtraData() {}

void NiTextKeyExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTextKeyExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTextKeyExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextKeyExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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

const Type & NiTextKeyExtraData::TypeConst() {
	return TYPE;
}
