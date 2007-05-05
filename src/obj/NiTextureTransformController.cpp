/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextureTransformController.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureTransformController::TYPE("NiTextureTransformController", &NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT::TYPE );

NiTextureTransformController::NiTextureTransformController() NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTextureTransformController::~NiTextureTransformController() {}

void NiTextureTransformController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTextureTransformController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTextureTransformController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextureTransformController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTextureTransformController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextureTransformController::GetType() const {
	return TYPE;
};
