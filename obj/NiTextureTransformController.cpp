/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTextureTransformController.h"
#include "NiFloatData.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiTextureTransformController::TYPE("NiTextureTransformController", &NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT::TypeConst() );

NiTextureTransformController::NiTextureTransformController() NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTextureTransformController::~NiTextureTransformController() {}

void NiTextureTransformController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURE_TRANSFORM_CONTROLLER_READ
}

void NiTextureTransformController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TEXTURE_TRANSFORM_CONTROLLER_WRITE
}

string NiTextureTransformController::asString( bool verbose ) const {
	NI_TEXTURE_TRANSFORM_CONTROLLER_STRING
}

void NiTextureTransformController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURE_TRANSFORM_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiTextureTransformController::GetRefs() const {
	NI_TEXTURE_TRANSFORM_CONTROLLER_GETREFS
}

const Type & NiTextureTransformController::GetType() const {
	return TYPE;
};

