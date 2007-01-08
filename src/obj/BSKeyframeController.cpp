/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSKeyframeController::TYPE("BSKeyframeController", &B_S_KEYFRAME_CONTROLLER_PARENT::TypeConst() );

BSKeyframeController::BSKeyframeController() B_S_KEYFRAME_CONTROLLER_CONSTRUCT {}

BSKeyframeController::~BSKeyframeController() {}

void BSKeyframeController::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void BSKeyframeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string BSKeyframeController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSKeyframeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> BSKeyframeController::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSKeyframeController::GetType() const {
	return TYPE;
};

