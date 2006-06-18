/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiVisController.h"
#include "NiVisData.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiVisController::TYPE("NiVisController", &NI_VIS_CONTROLLER_PARENT::TypeConst() );

NiVisController::NiVisController() NI_VIS_CONTROLLER_CONSTRUCT {}

NiVisController::~NiVisController() {}

void NiVisController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VIS_CONTROLLER_READ
}

void NiVisController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_VIS_CONTROLLER_WRITE
}

string NiVisController::asString( bool verbose ) const {
	NI_VIS_CONTROLLER_STRING
}

void NiVisController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_VIS_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiVisController::GetRefs() const {
	NI_VIS_CONTROLLER_GETREFS
}

const Type & NiVisController::GetType() const {
	return TYPE;
};

