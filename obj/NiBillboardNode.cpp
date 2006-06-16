/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBillboardNode.h"

//Definition of TYPE constant
const Type NiBillboardNode::TYPE("NiBillboardNode", &NI_BILLBOARD_NODE_PARENT::TypeConst() );

NiBillboardNode::NiBillboardNode() NI_BILLBOARD_NODE_CONSTRUCT {}

NiBillboardNode::~NiBillboardNode() {}

void NiBillboardNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BILLBOARD_NODE_READ
}

void NiBillboardNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BILLBOARD_NODE_WRITE
}

string NiBillboardNode::asString( bool verbose ) const {
	NI_BILLBOARD_NODE_STRING
}

void NiBillboardNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BILLBOARD_NODE_FIXLINKS
}

list<NiObjectRef> NiBillboardNode::GetRefs() const {
	NI_BILLBOARD_NODE_GETREFS
}

const Type & NiBillboardNode::GetType() const {
	return TYPE;
};

