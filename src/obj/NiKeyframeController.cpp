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
	InternalRead( in, link_stack, version, user_version );
}

void NiKeyframeController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiKeyframeController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiKeyframeController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiKeyframeController::GetRefs() const {
	return InternalGetRefs();
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
