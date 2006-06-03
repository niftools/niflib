/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkBlendCollisionObject.h"

//Definition of TYPE constant
const Type bhkBlendCollisionObject::TYPE("bhkBlendCollisionObject", &BHK_BLEND_COLLISION_OBJECT_PARENT::TYPE );

bhkBlendCollisionObject::bhkBlendCollisionObject() BHK_BLEND_COLLISION_OBJECT_CONSTRUCT {}

bhkBlendCollisionObject::~bhkBlendCollisionObject() {}

void bhkBlendCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	BHK_BLEND_COLLISION_OBJECT_READ
}

void bhkBlendCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_BLEND_COLLISION_OBJECT_WRITE
}

string bhkBlendCollisionObject::asString( bool verbose ) const {
	BHK_BLEND_COLLISION_OBJECT_STRING
}

void bhkBlendCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	BHK_BLEND_COLLISION_OBJECT_FIXLINKS
}

const Type & bhkBlendCollisionObject::GetType() const {
	return TYPE;
};

