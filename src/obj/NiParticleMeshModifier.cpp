/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleMeshModifier.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleMeshModifier::TYPE("NiParticleMeshModifier", &NI_PARTICLE_MESH_MODIFIER_PARENT::TypeConst() );

NiParticleMeshModifier::NiParticleMeshModifier() NI_PARTICLE_MESH_MODIFIER_CONSTRUCT {}

NiParticleMeshModifier::~NiParticleMeshModifier() {}

void NiParticleMeshModifier::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_MESH_MODIFIER_READ
}

void NiParticleMeshModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLE_MESH_MODIFIER_WRITE
}

string NiParticleMeshModifier::asString( bool verbose ) const {
	NI_PARTICLE_MESH_MODIFIER_STRING
}

void NiParticleMeshModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLE_MESH_MODIFIER_FIXLINKS
}

list<NiObjectRef> NiParticleMeshModifier::GetRefs() const {
	NI_PARTICLE_MESH_MODIFIER_GETREFS
}

const Type & NiParticleMeshModifier::GetType() const {
	return TYPE;
};

