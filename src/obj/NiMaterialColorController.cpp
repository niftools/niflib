/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMaterialColorController.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMaterialColorController::TYPE("NiMaterialColorController", &NI_MATERIAL_COLOR_CONTROLLER_PARENT::TypeConst() );

NiMaterialColorController::NiMaterialColorController() NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT {}

NiMaterialColorController::~NiMaterialColorController() {}

void NiMaterialColorController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiMaterialColorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiMaterialColorController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMaterialColorController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiMaterialColorController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMaterialColorController::GetType() const {
	return TYPE;
};

