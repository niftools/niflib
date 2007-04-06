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

void NiPSysEmitterCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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

const Type & NiPSysEmitterCtlr::TypeConst() {
	return TYPE;
}
