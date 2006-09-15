/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoneLODController.h"
#include "../../include/gen/SkinShapeGroup.h"
#include "../../include/gen/SkinShape.h"
#include "../../include/obj/NiTriShape.h"
#include "../../include/obj/NiSkinInstance.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoneLODController::TYPE("NiBoneLODController", &NI_BONE_L_O_D_CONTROLLER_PARENT::TypeConst() );

NiBoneLODController::NiBoneLODController() NI_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

NiBoneLODController::~NiBoneLODController() {}

void NiBoneLODController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BONE_L_O_D_CONTROLLER_READ
}

void NiBoneLODController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BONE_L_O_D_CONTROLLER_WRITE
}

string NiBoneLODController::asString( bool verbose ) const {
	NI_BONE_L_O_D_CONTROLLER_STRING
}

void NiBoneLODController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BONE_L_O_D_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiBoneLODController::GetRefs() const {
	NI_BONE_L_O_D_CONTROLLER_GETREFS
}

const Type & NiBoneLODController::GetType() const {
	return TYPE;
};

