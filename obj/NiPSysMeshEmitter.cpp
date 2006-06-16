/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysMeshEmitter.h"
#include "NiTriBasedGeom.h"

//Definition of TYPE constant
const Type NiPSysMeshEmitter::TYPE("NiPSysMeshEmitter", &NI_P_SYS_MESH_EMITTER_PARENT::TypeConst() );

NiPSysMeshEmitter::NiPSysMeshEmitter() NI_P_SYS_MESH_EMITTER_CONSTRUCT {}

NiPSysMeshEmitter::~NiPSysMeshEmitter() {}

void NiPSysMeshEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_MESH_EMITTER_READ
}

void NiPSysMeshEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_MESH_EMITTER_WRITE
}

string NiPSysMeshEmitter::asString( bool verbose ) const {
	NI_P_SYS_MESH_EMITTER_STRING
}

void NiPSysMeshEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_MESH_EMITTER_FIXLINKS
}

list<NiObjectRef> NiPSysMeshEmitter::GetRefs() const {
	NI_P_SYS_MESH_EMITTER_GETREFS
}

const Type & NiPSysMeshEmitter::GetType() const {
	return TYPE;
};

