/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkSPCollisionObject.h"

//Definition of TYPE constant
const Type bhkSPCollisionObject::TYPE("bhkSPCollisionObject", &BHK_S_P_COLLISION_OBJECT_PARENT::TYPE );

bhkSPCollisionObject::bhkSPCollisionObject() BHK_S_P_COLLISION_OBJECT_CONSTRUCT {}

bhkSPCollisionObject::~bhkSPCollisionObject() {}

void bhkSPCollisionObject::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	BHK_S_P_COLLISION_OBJECT_READ
}

void bhkSPCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_S_P_COLLISION_OBJECT_WRITE
}

string bhkSPCollisionObject::asString( bool verbose ) const {
	BHK_S_P_COLLISION_OBJECT_STRING
}

void bhkSPCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	BHK_S_P_COLLISION_OBJECT_FIXLINKS
}

