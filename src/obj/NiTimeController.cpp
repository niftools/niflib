/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiTimeController.h"
#include "../../include/obj/NiObjectNET.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTimeController::TYPE("NiTimeController", &NI_TIME_CONTROLLER_PARENT::TYPE );

NiTimeController::NiTimeController() NI_TIME_CONTROLLER_CONSTRUCT {}

NiTimeController::~NiTimeController() {}

void NiTimeController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTimeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTimeController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTimeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTimeController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTimeController::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

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

unsigned short NiTimeController::GetFlags() const {
	return flags;
}

void NiTimeController::SetFlags( unsigned short n ) {
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

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiTimeController"] = NiTimeController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiTimeController::Create() {
	return new NiTimeController;
}
