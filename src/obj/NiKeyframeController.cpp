/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiKeyframeController::TYPE("NiKeyframeController", &NI_KEYFRAME_CONTROLLER_PARENT::TypeConst() );

NiKeyframeController::NiKeyframeController() NI_KEYFRAME_CONTROLLER_CONSTRUCT {}

NiKeyframeController::~NiKeyframeController() {}

void NiKeyframeController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_KEYFRAME_CONTROLLER_READ
}

void NiKeyframeController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_KEYFRAME_CONTROLLER_WRITE
}

string NiKeyframeController::asString( bool verbose ) const {
	NI_KEYFRAME_CONTROLLER_STRING
}

void NiKeyframeController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_KEYFRAME_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiKeyframeController::GetRefs() const {
	NI_KEYFRAME_CONTROLLER_GETREFS
}

const Type & NiKeyframeController::GetType() const {
	return TYPE;
};

Ref<NiKeyframeData> NiKeyframeController::GetData() const {
	return data;
}
	
void NiKeyframeController::SetData( const Ref<NiKeyframeData> & n ) {
	data = n;
}