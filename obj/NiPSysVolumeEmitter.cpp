/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiPSysVolumeEmitter.h"
#include "obj/NiNode.h"

//Definition of TYPE constant
const Type NiPSysVolumeEmitter::TYPE("NiPSysVolumeEmitter", &NI_P_SYS_VOLUME_EMITTER_PARENT::TYPE );

NiPSysVolumeEmitter::NiPSysVolumeEmitter() NI_P_SYS_VOLUME_EMITTER_CONSTRUCT {}

NiPSysVolumeEmitter::~NiPSysVolumeEmitter() {}

void NiPSysVolumeEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_VOLUME_EMITTER_READ
}

void NiPSysVolumeEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_VOLUME_EMITTER_WRITE
}

string NiPSysVolumeEmitter::asString( bool verbose ) const {
	NI_P_SYS_VOLUME_EMITTER_STRING
}

void NiPSysVolumeEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_P_SYS_VOLUME_EMITTER_FIXLINKS
}

const Type & NiPSysVolumeEmitter::GetType() const {
	return TYPE;
};

