/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiKeyframeController::TYPE("NiKeyframeController", &NI_KEYFRAME_CONTROLLER_PARENT::TypeConst() );

NiKeyframeController::NiKeyframeController() NI_KEYFRAME_CONTROLLER_CONSTRUCT {}

NiKeyframeController::~NiKeyframeController() {}

void NiKeyframeController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiKeyframeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiKeyframeController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiKeyframeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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

const Type & NiKeyframeController::TypeConst() {
	return TYPE;
}
