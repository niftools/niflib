/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMaterialColorController.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMaterialColorController::TYPE("NiMaterialColorController", &NI_MATERIAL_COLOR_CONTROLLER_PARENT::TYPE );

NiMaterialColorController::NiMaterialColorController() NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT {}

NiMaterialColorController::~NiMaterialColorController() {}

void NiMaterialColorController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiMaterialColorController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiMaterialColorController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMaterialColorController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiMaterialColorController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMaterialColorController::GetType() const {
	return TYPE;
};
