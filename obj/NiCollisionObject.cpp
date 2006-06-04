/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiCollisionObject.h"
#include "obj/NiAVObject.h"
#include "obj/NiObject.h"

//Definition of TYPE constant
const Type NiCollisionObject::TYPE("NiCollisionObject", &NI_COLLISION_OBJECT_PARENT::TYPE );

NiCollisionObject::NiCollisionObject() NI_COLLISION_OBJECT_CONSTRUCT {}

NiCollisionObject::~NiCollisionObject() {}

void NiCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_COLLISION_OBJECT_READ
}

void NiCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_COLLISION_OBJECT_WRITE
}

string NiCollisionObject::asString( bool verbose ) const {
	NI_COLLISION_OBJECT_STRING
}

void NiCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_COLLISION_OBJECT_FIXLINKS
}

list<NiObjectRef> NiCollisionObject::GetRefs() const {
	NI_COLLISION_OBJECT_GETREFS
}

const Type & NiCollisionObject::GetType() const {
	return TYPE;
};

NiAVObject * NiCollisionObject::Parent() const { return NULL; }
