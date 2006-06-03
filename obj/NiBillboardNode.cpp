/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBillboardNode.h"

//Definition of TYPE constant
const Type NiBillboardNode::TYPE("NiBillboardNode", &NI_BILLBOARD_NODE_PARENT::TYPE );

NiBillboardNode::NiBillboardNode() NI_BILLBOARD_NODE_CONSTRUCT {}

NiBillboardNode::~NiBillboardNode() {}

void NiBillboardNode::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_BILLBOARD_NODE_READ
}

void NiBillboardNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_BILLBOARD_NODE_WRITE
}

string NiBillboardNode::asString( bool verbose ) const {
	NI_BILLBOARD_NODE_STRING
}

void NiBillboardNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_BILLBOARD_NODE_FIXLINKS
}

const Type & NiBillboardNode::GetType() const {
	return TYPE;
};

