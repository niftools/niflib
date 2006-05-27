/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTextureTransformController.h"

//Definition of TYPE constant
const Type NiTextureTransformController::TYPE("NiTextureTransformController", &NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT::TYPE );

NiTextureTransformController::NiTextureTransformController() NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiTextureTransformController::~NiTextureTransformController() {}

void NiTextureTransformController::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_TEXTURE_TRANSFORM_CONTROLLER_READ
}

void NiTextureTransformController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TEXTURE_TRANSFORM_CONTROLLER_WRITE
}

string NiTextureTransformController::asString( bool verbose ) const {
	NI_TEXTURE_TRANSFORM_CONTROLLER_STRING
}

void NiTextureTransformController::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_TEXTURE_TRANSFORM_CONTROLLER_FIXLINKS
}

