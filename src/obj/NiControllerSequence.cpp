/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiControllerSequence.h"
#include "../../include/gen/ControllerLink.h"
#include "../../include/obj/NiInterpolator.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiStringPalette.h"
#include "../../include/gen/ControllerLink.h"
#include "../../include/obj/NiTextKeyExtraData.h"
#include "../../include/obj/NiControllerManager.h"
#include "../../include/obj/NiTimeController.h"
#include "../../include/obj/NiSingleInterpController.h"
#include "../../include/obj/NiObjectNET.h"
#include "../../include/obj/NiProperty.h"

using namespace Niflib;

//Definition of TYPE constant
const Type NiControllerSequence::TYPE("NiControllerSequence", &NI_CONTROLLER_SEQUENCE_PARENT::TYPE );

NiControllerSequence::NiControllerSequence() NI_CONTROLLER_SEQUENCE_CONSTRUCT {}

NiControllerSequence::~NiControllerSequence() {}

void NiControllerSequence::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiControllerSequence::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiControllerSequence::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiControllerSequence::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiControllerSequence::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiControllerSequence::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

NiControllerManager * NiControllerSequence::GetParent() const { 
   return manager; 
}

void NiControllerSequence::SetParent(NiControllerManager * parent) { 
   manager = parent; 
}

void NiControllerSequence::SetTextKey( NiTextKeyExtraData * txt_key ) {
	//Set new name
	textKeysName = txt_key->GetName();
	textKeys = txt_key;
}

void NiControllerSequence::AddController( NiTimeController * obj ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence.");
	}

	NiObjectNETRef target = obj->GetTarget();
	if ( target == NULL ) {
		throw runtime_error("Controller must have a target to be added to a NiControllerSequence.");
	}

	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;
	cl.controller = obj;
	cl.targetName = target->GetName();
	cl.nodeName = target->GetName();

	NiPropertyRef prop = DynamicCast<NiProperty>(target);
	if ( prop != NULL ) {
		cl.propertyType = prop->GetType().GetTypeName();
	}

	cl.controllerType = obj->GetType().GetTypeName();

	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}

void NiControllerSequence::AddInterpolator( NiSingleInterpController * obj, byte priority ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence block.");
	}

	NiInterpolatorRef interp = obj->GetInterpolator();
	if ( interp == NULL ) {
		throw runtime_error("Controller must have an interpolator attached to be added to a NiControllerSequence with the AddInterpolator function.");
	}

	NiObjectNETRef target = obj->GetTarget();
	if ( target == NULL ) {
		throw runtime_error("Controller must have a target to be added to a NiControllerSequence.");
	}

	//If there are existing ControllerLinks, use the same StringPalette they're using
   if ( stringPalette == NULL ) {
      stringPalette = new NiStringPalette;
	}

	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;

	cl.interpolator = interp;
	cl.priority_ = priority;
   cl.stringPalette = stringPalette;
	cl.nodeNameOffset = stringPalette->AddSubStr( target->GetName() );

	NiPropertyRef prop = DynamicCast<NiProperty>(target);
	if ( prop != NULL ) {
		cl.propertyTypeOffset = stringPalette->AddSubStr( prop->GetType().GetTypeName() );
	}

	cl.controllerTypeOffset = stringPalette->AddSubStr( obj->GetType().GetTypeName() );

	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}

void NiControllerSequence::ClearControllerData() {
	
	throw runtime_error("The AddInterpolator function cannot be implemented until prolems in the XML are solved.");

	//Clear list
	controlledBlocks.clear();
}

vector<ControllerLink> NiControllerSequence::GetControllerData() const {
	return controlledBlocks;
}

Ref<NiTextKeyExtraData> NiControllerSequence::GetTextKeyExtraData() const {
	return textKeys;
}


float NiControllerSequence::GetFrequency() const {
	return frequency;
}

void NiControllerSequence::SetFrequency( float value ) {
	frequency = value;
}

float NiControllerSequence::GetStartTime() const {
	return startTime;
}

void NiControllerSequence::SetStartTime( float value ) {
	startTime = value;
}

float NiControllerSequence::GetStopTime() const {
	return stopTime;
}

void NiControllerSequence::SetStopTime( float value ) {
	stopTime = value;
}

CycleType NiControllerSequence::GetCycleType() const {
	return CycleType(cycleType);
}

void NiControllerSequence::SetCycleType( CycleType n ) {
	cycleType = n;
}

int NiControllerSequence::GetNumControllers() const {
   return int(controlledBlocks.size());
}

int NiControllerSequence::GetControllerPriority( int controller ) const {
   if (controller < 0 && controller < int(controlledBlocks.size())) {
      throw runtime_error("Invalid controller index.");
   }   
   return int(controlledBlocks[controller].priority_);
}

void NiControllerSequence::SetControllerPriority( int controller, int priority ) {
   if (controller < 0 && controller < int(controlledBlocks.size())) {
      throw runtime_error("Invalid controller index.");
   }   
   if (priority < 0 || priority > int(0xFF)) {
      throw runtime_error("Invalid priority must be between 0 and 255.");
   }
   controlledBlocks[controller].priority_ = priority;
}

string NiControllerSequence::GetName() const {
	return name;
}

void NiControllerSequence::SetName( const string & value ) {
	name = value;
}

string NiControllerSequence::GetTargetName() const {
	return targetName;
}

void NiControllerSequence::SetTargetName( const string & value ) {
	targetName = value;
}

float NiControllerSequence::GetWeight() const {
	return weight;
}

void NiControllerSequence::SetWeight( const float value ) {
	weight = value;
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
		global_object_map["NiControllerSequence"] = NiControllerSequence::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiControllerSequence::Create() {
	return new NiControllerSequence;
}
