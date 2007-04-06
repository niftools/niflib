/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFlipController.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFlipController::TYPE("NiFlipController", &NI_FLIP_CONTROLLER_PARENT::TypeConst() );

NiFlipController::NiFlipController() NI_FLIP_CONTROLLER_CONSTRUCT {}

NiFlipController::~NiFlipController() {}

void NiFlipController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiFlipController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiFlipController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFlipController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiFlipController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFlipController::GetType() const {
	return TYPE;
};

const Type & NiFlipController::TypeConst() {
	return TYPE;
}
