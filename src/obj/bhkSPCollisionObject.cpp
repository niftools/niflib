/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSPCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSPCollisionObject::TYPE("bhkSPCollisionObject", &BHK_S_P_COLLISION_OBJECT_PARENT::TypeConst() );

bhkSPCollisionObject::bhkSPCollisionObject() BHK_S_P_COLLISION_OBJECT_CONSTRUCT {}

bhkSPCollisionObject::~bhkSPCollisionObject() {}

void bhkSPCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkSPCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkSPCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSPCollisionObject::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkSPCollisionObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSPCollisionObject::GetType() const {
	return TYPE;
};

