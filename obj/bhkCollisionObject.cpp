/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkCollisionObject.h"
using namespace NifLib;

//Definition of TYPE constant
const Type bhkCollisionObject::TYPE("bhkCollisionObject", &BHK_COLLISION_OBJECT_PARENT::TypeConst() );

bhkCollisionObject::bhkCollisionObject() BHK_COLLISION_OBJECT_CONSTRUCT {}

bhkCollisionObject::~bhkCollisionObject() {}

void bhkCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_COLLISION_OBJECT_READ
}

void bhkCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_COLLISION_OBJECT_WRITE
}

string bhkCollisionObject::asString( bool verbose ) const {
	BHK_COLLISION_OBJECT_STRING
}

void bhkCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_COLLISION_OBJECT_FIXLINKS
}

list<NiObjectRef> bhkCollisionObject::GetRefs() const {
	BHK_COLLISION_OBJECT_GETREFS
}

const Type & bhkCollisionObject::GetType() const {
	return TYPE;
};

