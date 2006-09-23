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
	InternalRead( in, link_stack, version, user_version );
}

void NiAlphaController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiAlphaController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAlphaController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiAlphaController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAlphaController::GetType() const {
	return TYPE;
};

