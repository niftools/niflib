/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiColorData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiColorData::TYPE("NiColorData", &NI_COLOR_DATA_PARENT::TypeConst() );

NiColorData::NiColorData() NI_COLOR_DATA_CONSTRUCT {}

NiColorData::~NiColorData() {}

void NiColorData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiColorData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiColorData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiColorData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiColorData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiColorData::GetType() const {
	return TYPE;
};

KeyType NiColorData::GetKeyType() const {
	return data.interpolation;
}

void NiColorData::SetKeyType( KeyType t ) {
	data.interpolation = t;
}

vector< Key<Color4> > NiColorData::GetKeys() const {
	return data.keys;
}

void NiColorData::SetKeys( vector< Key<Color4> > const & keys ) {
	data.keys = keys;
}

