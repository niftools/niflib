/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTransformController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformController::TYPE("NiTransformController", &NI_TRANSFORM_CONTROLLER_PARENT::TypeConst() );

NiTransformController::NiTransformController() NI_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTransformController::~NiTransformController() {}

void NiTransformController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTransformController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTransformController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTransformController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTransformController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTransformController::GetType() const {
	return TYPE;
};

