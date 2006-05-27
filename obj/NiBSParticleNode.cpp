/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBSParticleNode.h"

//Definition of TYPE constant
const Type NiBSParticleNode::TYPE("NiBSParticleNode", &NI_B_S_PARTICLE_NODE_PARENT::TYPE );

NiBSParticleNode::NiBSParticleNode() NI_B_S_PARTICLE_NODE_CONSTRUCT {}

NiBSParticleNode::~NiBSParticleNode() {}

void NiBSParticleNode::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_B_S_PARTICLE_NODE_READ
}

void NiBSParticleNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_B_S_PARTICLE_NODE_WRITE
}

string NiBSParticleNode::asString( bool verbose ) const {
	NI_B_S_PARTICLE_NODE_STRING
}

void NiBSParticleNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_B_S_PARTICLE_NODE_FIXLINKS
}

