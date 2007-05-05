/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkBlendCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBlendCollisionObject::TYPE("bhkBlendCollisionObject", &BHK_BLEND_COLLISION_OBJECT_PARENT::TYPE );

bhkBlendCollisionObject::bhkBlendCollisionObject() BHK_BLEND_COLLISION_OBJECT_CONSTRUCT {}

bhkBlendCollisionObject::~bhkBlendCollisionObject() {}

void bhkBlendCollisionObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkBlendCollisionObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkBlendCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkBlendCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkBlendCollisionObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkBlendCollisionObject::GetType() const {
	return TYPE;
};
