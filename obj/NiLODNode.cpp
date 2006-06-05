/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiLODNode.h"
#include "../gen/LODRange.h"
#include "NiRangeLODData.h"

//Definition of TYPE constant
const Type NiLODNode::TYPE("NiLODNode", &NI_L_O_D_NODE_PARENT::TYPE );

NiLODNode::NiLODNode() NI_L_O_D_NODE_CONSTRUCT {}

NiLODNode::~NiLODNode() {}

void NiLODNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_L_O_D_NODE_READ
}

void NiLODNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_L_O_D_NODE_WRITE
}

string NiLODNode::asString( bool verbose ) const {
	NI_L_O_D_NODE_STRING
}

void NiLODNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_L_O_D_NODE_FIXLINKS
}

list<NiObjectRef> NiLODNode::GetRefs() const {
	NI_L_O_D_NODE_GETREFS
}

const Type & NiLODNode::GetType() const {
	return TYPE;
};

