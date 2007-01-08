/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSerializable.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSerializable::TYPE("bhkSerializable", &BHK_SERIALIZABLE_PARENT::TypeConst() );

bhkSerializable::bhkSerializable() BHK_SERIALIZABLE_CONSTRUCT {}

bhkSerializable::~bhkSerializable() {}

void bhkSerializable::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkSerializable::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkSerializable::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSerializable::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkSerializable::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSerializable::GetType() const {
	return TYPE;
};

