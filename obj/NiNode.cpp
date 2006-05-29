/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiNode.h"
#include "NiDynamicEffect.h"

//Definition of TYPE constant
const Type NiNode::TYPE("NiNode", &NI_NODE_PARENT::TYPE );

NiNode::NiNode() NI_NODE_CONSTRUCT {}

NiNode::~NiNode() {}

void NiNode::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_NODE_READ
}

void NiNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_NODE_WRITE
}

string NiNode::asString( bool verbose ) const {
	NI_NODE_STRING
}

void NiNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_NODE_FIXLINKS
}
