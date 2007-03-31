/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSAnimationNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSAnimationNode::TYPE("NiBSAnimationNode", &NI_B_S_ANIMATION_NODE_PARENT::TypeConst() );

NiBSAnimationNode::NiBSAnimationNode() NI_B_S_ANIMATION_NODE_CONSTRUCT {}

NiBSAnimationNode::~NiBSAnimationNode() {}

void NiBSAnimationNode::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBSAnimationNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBSAnimationNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSAnimationNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBSAnimationNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSAnimationNode::GetType() const {
	return TYPE;
};

const Type & NiBSAnimationNode::TypeConst() {
	return TYPE;
}
