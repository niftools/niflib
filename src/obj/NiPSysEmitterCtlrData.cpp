/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterCtlrData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterCtlrData::TYPE("NiPSysEmitterCtlrData", &NI_P_SYS_EMITTER_CTLR_DATA_PARENT::TypeConst() );

NiPSysEmitterCtlrData::NiPSysEmitterCtlrData() NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT {}

NiPSysEmitterCtlrData::~NiPSysEmitterCtlrData() {}

void NiPSysEmitterCtlrData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysEmitterCtlrData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysEmitterCtlrData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterCtlrData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysEmitterCtlrData::GetRefs() const {
	return InternalGetRefs();
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

const Type & NiPSysEmitterCtlrData::TypeConst() {
	return TYPE;
}
