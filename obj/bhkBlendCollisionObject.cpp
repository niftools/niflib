/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkBlendCollisionObject.h"

//Definition of TYPE constant
const Type bhkBlendCollisionObject::TYPE("bhkBlendCollisionObject", &BHK_BLEND_COLLISION_OBJECT_PARENT::TypeConst() );

bhkBlendCollisionObject::bhkBlendCollisionObject() BHK_BLEND_COLLISION_OBJECT_CONSTRUCT {}

bhkBlendCollisionObject::~bhkBlendCollisionObject() {}

void bhkBlendCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_BLEND_COLLISION_OBJECT_READ
}

void bhkBlendCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_BLEND_COLLISION_OBJECT_WRITE
}

string bhkBlendCollisionObject::asString( bool verbose ) const {
	BHK_BLEND_COLLISION_OBJECT_STRING
}

void bhkBlendCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_BLEND_COLLISION_OBJECT_FIXLINKS
}

list<NiObjectRef> bhkBlendCollisionObject::GetRefs() const {
	BHK_BLEND_COLLISION_OBJECT_GETREFS
}

const Type & bhkBlendCollisionObject::GetType() const {
	return TYPE;
};

