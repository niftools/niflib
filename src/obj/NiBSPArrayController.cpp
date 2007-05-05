/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSPArrayController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSPArrayController::TYPE("NiBSPArrayController", &NI_B_S_P_ARRAY_CONTROLLER_PARENT::TYPE );

NiBSPArrayController::NiBSPArrayController() NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT {}

NiBSPArrayController::~NiBSPArrayController() {}

void NiBSPArrayController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSPArrayController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSPArrayController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSPArrayController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSPArrayController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSPArrayController::GetType() const {
	return TYPE;
};
