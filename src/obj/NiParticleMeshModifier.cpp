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
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleMeshModifier::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleMeshModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleMeshModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleMeshModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleMeshModifier::GetType() const {
	return TYPE;
};

