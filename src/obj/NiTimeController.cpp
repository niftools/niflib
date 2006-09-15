/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTimeController.h"
#include "../../include/obj/NiObjectNET.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTimeController::TYPE("NiTimeController", &NI_TIME_CONTROLLER_PARENT::TypeConst() );

NiTimeController::NiTimeController() NI_TIME_CONTROLLER_CONSTRUCT {}

NiTimeController::~NiTimeController() {}

void NiTimeController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TIME_CONTROLLER_READ
}

void NiTimeController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TIME_CONTROLLER_WRITE
}

string NiTimeController::asString( bool verbose ) const {
	NI_TIME_CONTROLLER_STRING
}

void NiTimeController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TIME_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiTimeController::GetRefs() const {
	NI_TIME_CONTROLLER_GETREFS
}

const Type & NiTimeController::GetType() const {
	return TYPE;
};

NiTimeControllerRef NiTimeController::GetNextController() const {
	return nextController;
}

void NiTimeController::SetNextController( const NiTimeControllerRef & obj ) {
	nextController = obj;
}

void NiTimeController::SetTarget( NiObjectNET * new_target ) {
	target = new_target;
}

Ref<NiObjectNET> NiTimeController::GetTarget() {
	return target;
}

ushort NiTimeController::GetFlags() const {
	return flags;
}

void NiTimeController::SetFlags( ushort n ) {
	flags = n;
}

float NiTimeController::GetFrequency() const {
	return frequency;
}

void NiTimeController::SetFrequency( float n ) {
	frequency = n;
}

float NiTimeController::GetPhase() const {
	return phase;
}

void NiTimeController::SetPhase( float n ) {
	phase = n;
}

float NiTimeController::GetStartTime() const {
	return startTime;
}

void NiTimeController::SetStartTime( float n ) {
	startTime = n;
}

float NiTimeController::GetStopTime() const {
	return stopTime;
}

void NiTimeController::SetStopTime( float n ) {
	stopTime = n;
}
