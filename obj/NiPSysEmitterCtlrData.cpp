/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysEmitterCtlrData.h"

//Definition of TYPE constant
const Type NiPSysEmitterCtlrData::TYPE("NiPSysEmitterCtlrData", &NI_P_SYS_EMITTER_CTLR_DATA_PARENT::TYPE );

NiPSysEmitterCtlrData::NiPSysEmitterCtlrData() NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT {}

NiPSysEmitterCtlrData::~NiPSysEmitterCtlrData() {}

void NiPSysEmitterCtlrData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_EMITTER_CTLR_DATA_READ
}

void NiPSysEmitterCtlrData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_EMITTER_CTLR_DATA_WRITE
}

string NiPSysEmitterCtlrData::asString( bool verbose ) const {
	NI_P_SYS_EMITTER_CTLR_DATA_STRING
}

void NiPSysEmitterCtlrData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_EMITTER_CTLR_DATA_FIXLINKS
}

