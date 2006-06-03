/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/ABoneLODController.h"
#include "gen/NodeGroup.h"

//Definition of TYPE constant
const Type ABoneLODController::TYPE("ABoneLODController", &A_BONE_L_O_D_CONTROLLER_PARENT::TYPE );

ABoneLODController::ABoneLODController() A_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

ABoneLODController::~ABoneLODController() {}

void ABoneLODController::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	A_BONE_L_O_D_CONTROLLER_READ
}

void ABoneLODController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	A_BONE_L_O_D_CONTROLLER_WRITE
}

string ABoneLODController::asString( bool verbose ) const {
	A_BONE_L_O_D_CONTROLLER_STRING
}

void ABoneLODController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	A_BONE_L_O_D_CONTROLLER_FIXLINKS
}

const Type & ABoneLODController::GetType() const {
	return TYPE;
};

