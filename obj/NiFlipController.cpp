/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiFlipController.h"
#include "NiSourceTexture.h"

//Definition of TYPE constant
const Type NiFlipController::TYPE("NiFlipController", &NI_FLIP_CONTROLLER_PARENT::TypeConst() );

NiFlipController::NiFlipController() NI_FLIP_CONTROLLER_CONSTRUCT {}

NiFlipController::~NiFlipController() {}

void NiFlipController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLIP_CONTROLLER_READ
}

void NiFlipController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_FLIP_CONTROLLER_WRITE
}

string NiFlipController::asString( bool verbose ) const {
	NI_FLIP_CONTROLLER_STRING
}

void NiFlipController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_FLIP_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiFlipController::GetRefs() const {
	NI_FLIP_CONTROLLER_GETREFS
}

const Type & NiFlipController::GetType() const {
	return TYPE;
};

