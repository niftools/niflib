/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AvoidNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AvoidNode::TYPE("AvoidNode", &AVOID_NODE_PARENT::TypeConst() );

AvoidNode::AvoidNode() AVOID_NODE_CONSTRUCT {}

AvoidNode::~AvoidNode() {}

void AvoidNode::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void AvoidNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string AvoidNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AvoidNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> AvoidNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & AvoidNode::GetType() const {
	return TYPE;
};

const Type & AvoidNode::TypeConst() {
	return TYPE;
}
