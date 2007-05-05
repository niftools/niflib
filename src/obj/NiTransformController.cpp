/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTransformController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformController::TYPE("NiTransformController", &NI_TRANSFORM_CONTROLLER_PARENT::TYPE );

NiTransformController::NiTransformController() NI_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTransformController::~NiTransformController() {}

void NiTransformController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTransformController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTransformController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTransformController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTransformController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTransformController::GetType() const {
	return TYPE;
};
