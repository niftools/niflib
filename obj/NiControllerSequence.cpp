/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiControllerSequence.h"
#include "../gen/ControllerLink.h"
#include "NiInterpolator.h"
#include "NiObject.h"
#include "NiStringPalette.h"
#include "../gen/ControllerLink.h"
#include "NiInterpolator.h"
#include "NiObject.h"
#include "NiStringPalette.h"
#include "NiTextKeyExtraData.h"
#include "NiControllerManager.h"
#include "NiStringPalette.h"
#include "NiTimeController.h"
#include "NiSingleInterpolatorController.h"
#include "NiObjectNET.h"
#include "NiProperty.h"
#include "NiStringPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiControllerSequence::TYPE("NiControllerSequence", &NI_CONTROLLER_SEQUENCE_PARENT::TypeConst() );

NiControllerSequence::NiControllerSequence() NI_CONTROLLER_SEQUENCE_CONSTRUCT {}

NiControllerSequence::~NiControllerSequence() {}

void NiControllerSequence::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CONTROLLER_SEQUENCE_READ
}

void NiControllerSequence::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_CONTROLLER_SEQUENCE_WRITE
}

string NiControllerSequence::asString( bool verbose ) const {
	NI_CONTROLLER_SEQUENCE_STRING
}

void NiControllerSequence::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CONTROLLER_SEQUENCE_FIXLINKS
}

list<NiObjectRef> NiControllerSequence::GetRefs() const {
	NI_CONTROLLER_SEQUENCE_GETREFS
}

const Type & NiControllerSequence::GetType() const {
	return TYPE;
};

NiControllerManager * NiControllerSequence::Parent() const { return NULL; }

void NiControllerSequence::SetTextKey( const Ref<NiTextKeyExtraData> & txt_key ) {
	//Set new name
	textKeysName = txt_key->GetName();
	textKeys = txt_key;
}

void NiControllerSequence::AddController( const Ref<NiTimeController> & obj ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence block.");
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

void NiControllerSequence::AddInterpolator( const Ref<NiSingleInterpolatorController> & obj, byte priority ) {
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
