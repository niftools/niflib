/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoolData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoolData::TYPE("NiBoolData", &NI_BOOL_DATA_PARENT::TypeConst() );

NiBoolData::NiBoolData() NI_BOOL_DATA_CONSTRUCT {}

NiBoolData::~NiBoolData() {}

void NiBoolData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBoolData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBoolData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBoolData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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

const Type & NiBoolData::TypeConst() {
	return TYPE;
}
