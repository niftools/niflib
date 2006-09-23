/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiCollisionObject.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionObject::TYPE("NiCollisionObject", &NI_COLLISION_OBJECT_PARENT::TypeConst() );

NiCollisionObject::NiCollisionObject() NI_COLLISION_OBJECT_CONSTRUCT {}

NiCollisionObject::~NiCollisionObject() {}

void NiCollisionObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiCollisionObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiCollisionObject::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiCollisionObject::GetRefs() const {
	return InternalGetRefs();
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
