/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiBoneLODController.h"

//Definition of TYPE constant
const Type NiBoneLODController::TYPE("NiBoneLODController", &NI_BONE_L_O_D_CONTROLLER_PARENT::TYPE );

NiBoneLODController::NiBoneLODController() NI_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

NiBoneLODController::~NiBoneLODController() {}

void NiBoneLODController::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_BONE_L_O_D_CONTROLLER_READ
}

void NiBoneLODController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_BONE_L_O_D_CONTROLLER_WRITE
}

string NiBoneLODController::asString( bool verbose ) const {
	NI_BONE_L_O_D_CONTROLLER_STRING
}

void NiBoneLODController::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_BONE_L_O_D_CONTROLLER_FIXLINKS
}

