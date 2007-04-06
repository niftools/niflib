/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSParticleNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSParticleNode::TYPE("NiBSParticleNode", &NI_B_S_PARTICLE_NODE_PARENT::TypeConst() );

NiBSParticleNode::NiBSParticleNode() NI_B_S_PARTICLE_NODE_CONSTRUCT {}

NiBSParticleNode::~NiBSParticleNode() {}

void NiBSParticleNode::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSParticleNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSParticleNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSParticleNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSParticleNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSParticleNode::GetType() const {
	return TYPE;
};

const Type & NiBSParticleNode::TypeConst() {
	return TYPE;
}
