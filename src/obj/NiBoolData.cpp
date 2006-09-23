/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoolData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoolData::TYPE("NiBoolData", &NI_BOOL_DATA_PARENT::TypeConst() );

NiBoolData::NiBoolData() NI_BOOL_DATA_CONSTRUCT {}

NiBoolData::~NiBoolData() {}

void NiBoolData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBoolData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBoolData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBoolData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBoolData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBoolData::GetType() const {
	return TYPE;
};

KeyType NiBoolData::GetKeyType() const {
	return data.interpolation;
}

void NiBoolData::SetKeyType( KeyType t ) {
	data.interpolation= t;
}

vector< Key<unsigned char> > NiBoolData::GetKeys() const {
	return data.keys;
}

void NiBoolData::SetKeys( vector< Key<unsigned char> > const & keys ) {
	data.keys = keys;
}
