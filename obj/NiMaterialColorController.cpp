/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiMaterialColorController.h"
#include "obj/NiPosData.h"

//Definition of TYPE constant
const Type NiMaterialColorController::TYPE("NiMaterialColorController", &NI_MATERIAL_COLOR_CONTROLLER_PARENT::TYPE );

NiMaterialColorController::NiMaterialColorController() NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT {}

NiMaterialColorController::~NiMaterialColorController() {}

void NiMaterialColorController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_MATERIAL_COLOR_CONTROLLER_READ
}

void NiMaterialColorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_MATERIAL_COLOR_CONTROLLER_WRITE
}

string NiMaterialColorController::asString( bool verbose ) const {
	NI_MATERIAL_COLOR_CONTROLLER_STRING
}

void NiMaterialColorController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_MATERIAL_COLOR_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiMaterialColorController::GetRefs() const {
	NI_MATERIAL_COLOR_CONTROLLER_GETREFS
}

const Type & NiMaterialColorController::GetType() const {
	return TYPE;
};

