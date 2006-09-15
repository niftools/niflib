/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterCtlrData.h"
#include "../../include/gen/KeyGroup.h"
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

KeyGroup<float > NiPSysEmitterCtlrData::GetFloatKeys_() const {
	return floatKeys_;
}

void NiPSysEmitterCtlrData::SetFloatKeys_( KeyGroup<float > value ) {
	floatKeys_ = value;
}

vector<Key<byte > > NiPSysEmitterCtlrData::GetVisibilityKeys_() const {
	return visibilityKeys_;
}

void NiPSysEmitterCtlrData::SetVisibilityKeys_( const vector<Key<byte > >& value ) {
	visibilityKeys_ = value;
}

