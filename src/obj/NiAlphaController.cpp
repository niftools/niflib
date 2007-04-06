/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAlphaController.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAlphaController::TYPE("NiAlphaController", &NI_ALPHA_CONTROLLER_PARENT::TypeConst() );

NiAlphaController::NiAlphaController() NI_ALPHA_CONTROLLER_CONSTRUCT {}

NiAlphaController::~NiAlphaController() {}

void NiAlphaController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAlphaController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAlphaController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAlphaController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAlphaController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAlphaController::GetType() const {
	return TYPE;
};

const Type & NiAlphaController::TypeConst() {
	return TYPE;
}
