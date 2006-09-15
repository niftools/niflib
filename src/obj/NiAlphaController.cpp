/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAlphaController.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAlphaController::TYPE("NiAlphaController", &NI_ALPHA_CONTROLLER_PARENT::TypeConst() );

NiAlphaController::NiAlphaController() NI_ALPHA_CONTROLLER_CONSTRUCT {}

NiAlphaController::~NiAlphaController() {}

void NiAlphaController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ALPHA_CONTROLLER_READ
}

void NiAlphaController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_ALPHA_CONTROLLER_WRITE
}

string NiAlphaController::asString( bool verbose ) const {
	NI_ALPHA_CONTROLLER_STRING
}

void NiAlphaController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ALPHA_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiAlphaController::GetRefs() const {
	NI_ALPHA_CONTROLLER_GETREFS
}

const Type & NiAlphaController::GetType() const {
	return TYPE;
};

