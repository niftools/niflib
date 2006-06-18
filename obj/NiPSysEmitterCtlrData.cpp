/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysEmitterCtlrData.h"
#include "../gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterCtlrData::TYPE("NiPSysEmitterCtlrData", &NI_P_SYS_EMITTER_CTLR_DATA_PARENT::TypeConst() );

NiPSysEmitterCtlrData::NiPSysEmitterCtlrData() NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT {}

NiPSysEmitterCtlrData::~NiPSysEmitterCtlrData() {}

void NiPSysEmitterCtlrData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_CTLR_DATA_READ
}

void NiPSysEmitterCtlrData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_EMITTER_CTLR_DATA_WRITE
}

string NiPSysEmitterCtlrData::asString( bool verbose ) const {
	NI_P_SYS_EMITTER_CTLR_DATA_STRING
}

void NiPSysEmitterCtlrData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_EMITTER_CTLR_DATA_FIXLINKS
}

list<NiObjectRef> NiPSysEmitterCtlrData::GetRefs() const {
	NI_P_SYS_EMITTER_CTLR_DATA_GETREFS
}

const Type & NiPSysEmitterCtlrData::GetType() const {
	return TYPE;
};

