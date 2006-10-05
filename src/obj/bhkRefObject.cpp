/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRefObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRefObject::TYPE("bhkRefObject", &BHK_REF_OBJECT_PARENT::TypeConst() );

bhkRefObject::bhkRefObject() BHK_REF_OBJECT_CONSTRUCT {}

bhkRefObject::~bhkRefObject() {}

void bhkRefObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkRefObject::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkRefObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRefObject::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkRefObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRefObject::GetType() const {
	return TYPE;
};

