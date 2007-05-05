/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiCollisionObject.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionObject::TYPE("NiCollisionObject", &NI_COLLISION_OBJECT_PARENT::TYPE );

NiCollisionObject::NiCollisionObject() NI_COLLISION_OBJECT_CONSTRUCT {}

NiCollisionObject::~NiCollisionObject() {}

void NiCollisionObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiCollisionObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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

void NiCollisionObject::SetBody( NiObject * value ) {
	body = value;
}
