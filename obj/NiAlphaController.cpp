/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiAlphaController.h"
#include "obj/NiFloatData.h"

//Definition of TYPE constant
const Type NiAlphaController::TYPE("NiAlphaController", &NI_ALPHA_CONTROLLER_PARENT::TYPE );

NiAlphaController::NiAlphaController() NI_ALPHA_CONTROLLER_CONSTRUCT {}

NiAlphaController::~NiAlphaController() {}

void NiAlphaController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_ALPHA_CONTROLLER_READ
}

void NiAlphaController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_ALPHA_CONTROLLER_WRITE
}

string NiAlphaController::asString( bool verbose ) const {
	NI_ALPHA_CONTROLLER_STRING
}

void NiAlphaController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_ALPHA_CONTROLLER_FIXLINKS
}

const Type & NiAlphaController::GetType() const {
	return TYPE;
};

