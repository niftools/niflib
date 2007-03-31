/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiExtraData::TYPE("NiExtraData", &NI_EXTRA_DATA_PARENT::TypeConst() );

NiExtraData::NiExtraData() NI_EXTRA_DATA_CONSTRUCT {}

NiExtraData::~NiExtraData() {}

void NiExtraData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiExtraData::GetType() const {
	return TYPE;
};

string NiExtraData::GetName() {
	return name;
}

void NiExtraData::SetName( const string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiExtraData::GetIDString() const {
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

const Type & NiExtraData::TypeConst() {
	return TYPE;
}
