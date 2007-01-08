/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AvoidNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AvoidNode::TYPE("AvoidNode", &AVOID_NODE_PARENT::TypeConst() );

AvoidNode::AvoidNode() AVOID_NODE_CONSTRUCT {}

AvoidNode::~AvoidNode() {}

void AvoidNode::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void AvoidNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string AvoidNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AvoidNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> AvoidNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & AvoidNode::GetType() const {
	return TYPE;
};

