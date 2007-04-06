/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSKeyframeController::TYPE("BSKeyframeController", &B_S_KEYFRAME_CONTROLLER_PARENT::TypeConst() );

BSKeyframeController::BSKeyframeController() B_S_KEYFRAME_CONTROLLER_CONSTRUCT {}

BSKeyframeController::~BSKeyframeController() {}

void BSKeyframeController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void BSKeyframeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string BSKeyframeController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSKeyframeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> BSKeyframeController::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSKeyframeController::GetType() const {
	return TYPE;
};

const Type & BSKeyframeController::TypeConst() {
	return TYPE;
}
