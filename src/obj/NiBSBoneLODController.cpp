/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSBoneLODController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSBoneLODController::TYPE("NiBSBoneLODController", &NI_B_S_BONE_L_O_D_CONTROLLER_PARENT::TypeConst() );

NiBSBoneLODController::NiBSBoneLODController() NI_B_S_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

NiBSBoneLODController::~NiBSBoneLODController() {}

void NiBSBoneLODController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBSBoneLODController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBSBoneLODController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSBoneLODController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBSBoneLODController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSBoneLODController::GetType() const {
	return TYPE;
};

