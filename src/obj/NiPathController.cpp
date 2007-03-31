/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPathController.h"
#include "../../include/obj/NiPosData.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPathController::TYPE("NiPathController", &NI_PATH_CONTROLLER_PARENT::TypeConst() );

NiPathController::NiPathController() NI_PATH_CONTROLLER_CONSTRUCT {}

NiPathController::~NiPathController() {}

void NiPathController::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPathController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPathController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPathController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPathController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPathController::GetType() const {
	return TYPE;
};

Ref<NiFloatData> NiPathController::GetFloatData() const {
	return floatData;
}

void NiPathController::SetFloatData( const Ref<NiFloatData> & n ) {
	floatData = n;
}

Ref<NiPosData> NiPathController::GetPosData() const {
	return posData;
}

void NiPathController::SetPosData( const Ref<NiPosData> & n ) {
	posData = n;
}

const Type & NiPathController::TypeConst() {
	return TYPE;
}
