/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatExtraDataController.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatExtraDataController::TYPE("NiFloatExtraDataController", &NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENT::TypeConst() );

NiFloatExtraDataController::NiFloatExtraDataController() NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT {}

NiFloatExtraDataController::~NiFloatExtraDataController() {}

void NiFloatExtraDataController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiFloatExtraDataController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiFloatExtraDataController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatExtraDataController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiFloatExtraDataController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatExtraDataController::GetType() const {
	return TYPE;
};

const Type & NiFloatExtraDataController::TypeConst() {
	return TYPE;
}
