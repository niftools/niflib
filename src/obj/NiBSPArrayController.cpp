/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSPArrayController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSPArrayController::TYPE("NiBSPArrayController", &NI_B_S_P_ARRAY_CONTROLLER_PARENT::TypeConst() );

NiBSPArrayController::NiBSPArrayController() NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT {}

NiBSPArrayController::~NiBSPArrayController() {}

void NiBSPArrayController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBSPArrayController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBSPArrayController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSPArrayController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBSPArrayController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSPArrayController::GetType() const {
	return TYPE;
};

