/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatData::TYPE("NiFloatData", &NI_FLOAT_DATA_PARENT::TypeConst() );

NiFloatData::NiFloatData() NI_FLOAT_DATA_CONSTRUCT {}

NiFloatData::~NiFloatData() {}

void NiFloatData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiFloatData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiFloatData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiFloatData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatData::GetType() const {
	return TYPE;
};

KeyType NiFloatData::GetKeyType() const {
	return data.interpolation;
}

void NiFloatData::SetKeyType( KeyType t ) {
	data.interpolation = t;
}

vector< Key<float> > NiFloatData::GetKeys() const {
	return data.keys;
}

void NiFloatData::SetKeys( vector< Key<float> > const & keys ) {
	data.keys = keys;
}


