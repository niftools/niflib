/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "AvoidNode.h"

//Definition of TYPE constant
const Type AvoidNode::TYPE("AvoidNode", &AVOID_NODE_PARENT::TYPE );

AvoidNode::AvoidNode() AVOID_NODE_CONSTRUCT {}

AvoidNode::~AvoidNode() {}

void AvoidNode::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  AVOID_NODE_READ
}

void AvoidNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  AVOID_NODE_WRITE
}

string AvoidNode::asString( bool verbose ) const {
  AVOID_NODE_STRING
}

void AvoidNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  AVOID_NODE_FIXLINKS
}

const Type & AvoidNode::GetType() const {
  return TYPE;
};

