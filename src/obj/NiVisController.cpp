/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVisController.h"
#include "../../include/obj/NiVisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVisController::TYPE("NiVisController", &NI_VIS_CONTROLLER_PARENT::TypeConst() );

NiVisController::NiVisController() NI_VIS_CONTROLLER_CONSTRUCT {}

NiVisController::~NiVisController() {}

void NiVisController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiVisController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiVisController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVisController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiVisController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVisController::GetType() const {
	return TYPE;
};

const Type & NiVisController::TypeConst() {
	return TYPE;
}
