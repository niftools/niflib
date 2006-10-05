/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTextureTransformController.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureTransformController::TYPE("NiTextureTransformController", &NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT::TypeConst() );

NiTextureTransformController::NiTextureTransformController() NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTextureTransformController::~NiTextureTransformController() {}

void NiTextureTransformController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTextureTransformController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTextureTransformController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextureTransformController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTextureTransformController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextureTransformController::GetType() const {
	return TYPE;
};

