/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiExtraData::TYPE("NiExtraData", &NI_EXTRA_DATA_PARENT::TypeConst() );

NiExtraData::NiExtraData() NI_EXTRA_DATA_CONSTRUCT {}

NiExtraData::~NiExtraData() {}

void NiExtraData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_EXTRA_DATA_READ
}

void NiExtraData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_EXTRA_DATA_WRITE
}

string NiExtraData::asString( bool verbose ) const {
	NI_EXTRA_DATA_STRING
}

void NiExtraData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_EXTRA_DATA_FIXLINKS
}

list<NiObjectRef> NiExtraData::GetRefs() const {
	NI_EXTRA_DATA_GETREFS
}

const Type & NiExtraData::GetType() const {
	return TYPE;
};

string NiExtraData::GetName() {
	return name;
}

void NiExtraData::SetName( string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiExtraData::GetIDString() {
	stringstream out;
	out << NiObject::GetIDString() << " {" << name << "}";
	return out.str();
}

NiExtraDataRef NiExtraData::GetNextExtraData() const {
	return nextExtraData;
}

void NiExtraData::SetNextExtraData( const NiExtraDataRef & obj ) {
	nextExtraData = obj;
}
