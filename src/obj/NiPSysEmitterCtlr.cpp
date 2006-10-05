/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterCtlr.h"
#include "../../include/obj/NiPSysEmitterCtlrData.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterCtlr::TYPE("NiPSysEmitterCtlr", &NI_P_SYS_EMITTER_CTLR_PARENT::TypeConst() );

NiPSysEmitterCtlr::NiPSysEmitterCtlr() NI_P_SYS_EMITTER_CTLR_CONSTRUCT {}

NiPSysEmitterCtlr::~NiPSysEmitterCtlr() {}

void NiPSysEmitterCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitterCtlr::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitterCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitterCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterCtlr::GetType() const {
	return TYPE;
};

Ref<NiPSysEmitterCtlrData > NiPSysEmitterCtlr::GetData() const {
	return data;
}

void NiPSysEmitterCtlr::SetData( Ref<NiPSysEmitterCtlrData > value ) {
	data = value;
}

Ref<NiInterpolator > NiPSysEmitterCtlr::GetVisibilityInterpolator() const {
	return visibilityInterpolator;
}

void NiPSysEmitterCtlr::SetVisibilityInterpolator( Ref<NiInterpolator > value ) {
	visibilityInterpolator = value;
}

