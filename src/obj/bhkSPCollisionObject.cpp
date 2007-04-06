/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSPCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSPCollisionObject::TYPE("bhkSPCollisionObject", &BHK_S_P_COLLISION_OBJECT_PARENT::TypeConst() );

bhkSPCollisionObject::bhkSPCollisionObject() BHK_S_P_COLLISION_OBJECT_CONSTRUCT {}

bhkSPCollisionObject::~bhkSPCollisionObject() {}

void bhkSPCollisionObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkSPCollisionObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkSPCollisionObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSPCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkSPCollisionObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSPCollisionObject::GetType() const {
	return TYPE;
};

const Type & bhkSPCollisionObject::TypeConst() {
	return TYPE;
}
