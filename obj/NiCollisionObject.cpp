/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiCollisionObject.h"
#include "NiAVObject.h"
#include "NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionObject::TYPE("NiCollisionObject", &NI_COLLISION_OBJECT_PARENT::TypeConst() );

NiCollisionObject::NiCollisionObject() NI_COLLISION_OBJECT_CONSTRUCT {}

NiCollisionObject::~NiCollisionObject() {}

void NiCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_COLLISION_OBJECT_READ
}

void NiCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_COLLISION_OBJECT_WRITE
}

string NiCollisionObject::asString( bool verbose ) const {
	NI_COLLISION_OBJECT_STRING
}

void NiCollisionObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_COLLISION_OBJECT_FIXLINKS
}

list<NiObjectRef> NiCollisionObject::GetRefs() const {
	NI_COLLISION_OBJECT_GETREFS
}

const Type & NiCollisionObject::GetType() const {
	return TYPE;
};

Ref<NiAVObject> NiCollisionObject::GetParent() const {
	return Ref<NiAVObject>(parent);
}

void NiCollisionObject::SetParent( NiAVObject * value ) {
	parent = value;
}

Ref<NiObject > NiCollisionObject::GetBody() const {
	return body;
}

void NiCollisionObject::SetBody( Ref<NiObject > value ) {
	body = value;
}
