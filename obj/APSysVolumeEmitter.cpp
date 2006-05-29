/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysVolumeEmitter.h"
#include "NiNode.h"

//Definition of TYPE constant
const Type APSysVolumeEmitter::TYPE("APSysVolumeEmitter", &A_P_SYS_VOLUME_EMITTER_PARENT::TYPE );

APSysVolumeEmitter::APSysVolumeEmitter() A_P_SYS_VOLUME_EMITTER_CONSTRUCT {}

APSysVolumeEmitter::~APSysVolumeEmitter() {}

void APSysVolumeEmitter::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	A_P_SYS_VOLUME_EMITTER_READ
}

void APSysVolumeEmitter::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_P_SYS_VOLUME_EMITTER_WRITE
}

string APSysVolumeEmitter::asString( bool verbose ) const {
	A_P_SYS_VOLUME_EMITTER_STRING
}

void APSysVolumeEmitter::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	A_P_SYS_VOLUME_EMITTER_FIXLINKS
}

