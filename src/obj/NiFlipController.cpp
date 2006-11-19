/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFlipController.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFlipController::TYPE("NiFlipController", &NI_FLIP_CONTROLLER_PARENT::TypeConst() );

NiFlipController::NiFlipController() NI_FLIP_CONTROLLER_CONSTRUCT {}

NiFlipController::~NiFlipController() {}

void NiFlipController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiFlipController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiFlipController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFlipController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiFlipController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFlipController::GetType() const {
	return TYPE;
};

