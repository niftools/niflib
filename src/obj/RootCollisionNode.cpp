/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/RootCollisionNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type RootCollisionNode::TYPE("RootCollisionNode", &ROOT_COLLISION_NODE_PARENT::TYPE );

RootCollisionNode::RootCollisionNode() ROOT_COLLISION_NODE_CONSTRUCT {}

RootCollisionNode::~RootCollisionNode() {}

void RootCollisionNode::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void RootCollisionNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string RootCollisionNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void RootCollisionNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> RootCollisionNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & RootCollisionNode::GetType() const {
	return TYPE;
};
