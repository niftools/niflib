/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCollisionObject::TYPE("bhkCollisionObject", &BHK_COLLISION_OBJECT_PARENT::TypeConst() );

bhkCollisionObject::bhkCollisionObject() BHK_COLLISION_OBJECT_CONSTRUCT {}

bhkCollisionObject::~bhkCollisionObject() {}

void bhkCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkCollisionObject::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkCollisionObject::GetRefs() const {
//	return InternalGetRefs();
	list<NiObjectRef> refs =  InternalGetRefs();
	refs.reverse();
	return refs;
}

const Type & bhkCollisionObject::GetType() const {
	return TYPE;
};

