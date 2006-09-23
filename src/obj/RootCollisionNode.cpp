/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/RootCollisionNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type RootCollisionNode::TYPE("RootCollisionNode", &ROOT_COLLISION_NODE_PARENT::TypeConst() );

RootCollisionNode::RootCollisionNode() ROOT_COLLISION_NODE_CONSTRUCT {}

RootCollisionNode::~RootCollisionNode() {}

void RootCollisionNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void RootCollisionNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string RootCollisionNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void RootCollisionNode::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> RootCollisionNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & RootCollisionNode::GetType() const {
	return TYPE;
};

