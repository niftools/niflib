/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSPCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSPCollisionObject::TYPE("bhkSPCollisionObject", &BHK_S_P_COLLISION_OBJECT_PARENT::TypeConst() );

bhkSPCollisionObject::bhkSPCollisionObject() BHK_S_P_COLLISION_OBJECT_CONSTRUCT {}

bhkSPCollisionObject::~bhkSPCollisionObject() {}

void bhkSPCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_S_P_COLLISION_OBJECT_READ
}

void bhkSPCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_S_P_COLLISION_OBJECT_WRITE
}

string bhkSPCollisionObject::asString( bool verbose ) const {
	BHK_S_P_COLLISION_OBJECT_STRING
}

void bhkSPCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_S_P_COLLISION_OBJECT_FIXLINKS
}

list<NiObjectRef> bhkSPCollisionObject::GetRefs() const {
	BHK_S_P_COLLISION_OBJECT_GETREFS
}

const Type & bhkSPCollisionObject::GetType() const {
	return TYPE;
};

