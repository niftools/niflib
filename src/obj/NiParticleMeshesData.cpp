/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiParticleMeshesData.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleMeshesData::TYPE("NiParticleMeshesData", &NI_PARTICLE_MESHES_DATA_PARENT::TypeConst() );

NiParticleMeshesData::NiParticleMeshesData() NI_PARTICLE_MESHES_DATA_CONSTRUCT {}

NiParticleMeshesData::~NiParticleMeshesData() {}

void NiParticleMeshesData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiParticleMeshesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiParticleMeshesData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiParticleMeshesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiParticleMeshesData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiParticleMeshesData::GetType() const {
	return TYPE;
};

const Type & NiParticleMeshesData::TypeConst() {
	return TYPE;
}
