/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiVisController.h"
#include "../../include/obj/NiVisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVisController::TYPE("NiVisController", &NI_VIS_CONTROLLER_PARENT::TypeConst() );

NiVisController::NiVisController() NI_VIS_CONTROLLER_CONSTRUCT {}

NiVisController::~NiVisController() {}

void NiVisController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiVisController::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiVisController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVisController::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiVisController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVisController::GetType() const {
	return TYPE;
};

