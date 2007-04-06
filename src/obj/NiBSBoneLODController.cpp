/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSBoneLODController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSBoneLODController::TYPE("NiBSBoneLODController", &NI_B_S_BONE_L_O_D_CONTROLLER_PARENT::TypeConst() );

NiBSBoneLODController::NiBSBoneLODController() NI_B_S_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

NiBSBoneLODController::~NiBSBoneLODController() {}

void NiBSBoneLODController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSBoneLODController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSBoneLODController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSBoneLODController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSBoneLODController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSBoneLODController::GetType() const {
	return TYPE;
};

const Type & NiBSBoneLODController::TypeConst() {
	return TYPE;
}
