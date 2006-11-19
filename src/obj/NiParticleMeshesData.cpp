/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleMeshesData.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleMeshesData::TYPE("NiParticleMeshesData", &NI_PARTICLE_MESHES_DATA_PARENT::TypeConst() );

NiParticleMeshesData::NiParticleMeshesData() NI_PARTICLE_MESHES_DATA_CONSTRUCT {}

NiParticleMeshesData::~NiParticleMeshesData() {}

void NiParticleMeshesData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiParticleMeshesData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiParticleMeshesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleMeshesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiParticleMeshesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleMeshesData::GetType() const {
	return TYPE;
};

