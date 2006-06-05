/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBSAnimationNode.h"

//Definition of TYPE constant
const Type NiBSAnimationNode::TYPE("NiBSAnimationNode", &NI_B_S_ANIMATION_NODE_PARENT::TYPE );

NiBSAnimationNode::NiBSAnimationNode() NI_B_S_ANIMATION_NODE_CONSTRUCT {}

NiBSAnimationNode::~NiBSAnimationNode() {}

void NiBSAnimationNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_S_ANIMATION_NODE_READ
}

void NiBSAnimationNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_B_S_ANIMATION_NODE_WRITE
}

string NiBSAnimationNode::asString( bool verbose ) const {
	NI_B_S_ANIMATION_NODE_STRING
}

void NiBSAnimationNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_B_S_ANIMATION_NODE_FIXLINKS
}

list<NiObjectRef> NiBSAnimationNode::GetRefs() const {
	NI_B_S_ANIMATION_NODE_GETREFS
}

const Type & NiBSAnimationNode::GetType() const {
	return TYPE;
};

