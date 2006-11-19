/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkBlendCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBlendCollisionObject::TYPE("bhkBlendCollisionObject", &BHK_BLEND_COLLISION_OBJECT_PARENT::TypeConst() );

bhkBlendCollisionObject::bhkBlendCollisionObject() BHK_BLEND_COLLISION_OBJECT_CONSTRUCT {}

bhkBlendCollisionObject::~bhkBlendCollisionObject() {}

void bhkBlendCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkBlendCollisionObject::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkBlendCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkBlendCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkBlendCollisionObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkBlendCollisionObject::GetType() const {
	return TYPE;
};

