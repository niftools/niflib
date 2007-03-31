/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysVolumeEmitter.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysVolumeEmitter::TYPE("NiPSysVolumeEmitter", &NI_P_SYS_VOLUME_EMITTER_PARENT::TypeConst() );

NiPSysVolumeEmitter::NiPSysVolumeEmitter() NI_P_SYS_VOLUME_EMITTER_CONSTRUCT {}

NiPSysVolumeEmitter::~NiPSysVolumeEmitter() {}

void NiPSysVolumeEmitter::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysVolumeEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysVolumeEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysVolumeEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysVolumeEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysVolumeEmitter::GetType() const {
	return TYPE;
};

const Type & NiPSysVolumeEmitter::TypeConst() {
	return TYPE;
}
