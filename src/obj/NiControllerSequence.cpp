/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiSingleInterpController.h"
#include "../../include/obj/NiObjectNET.h"
#include "../../include/obj/NiProperty.h"
#include "../../include/obj/NiInterpolator.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiControllerSequence.h"
#include "../../include/obj/NiTextKeyExtraData.h"
#include "../../include/obj/NiControllerManager.h"
#include "../../include/obj/NiStringPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiControllerSequence::TYPE("NiControllerSequence", &NiSequence::TYPE );

NiControllerSequence::NiControllerSequence() : weight(1.0f), textKeys(NULL), unknownInt0((unsigned int)0), frequency(0.0f), startTime(0.0f), stopTime(0.0f), unknownFloat2(0.0f), unknownByte((byte)0), manager(NULL), stringPalette(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiControllerSequence::~NiControllerSequence() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiControllerSequence::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Register this object type with Niflib
		ObjectRegistry::RegisterObject( "NiControllerSequence", NiControllerSequence::Create );

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiControllerSequence::Create() {
	return new NiControllerSequence;
}

void NiControllerSequence::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiSequence::Read( in, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( weight, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( cycleType, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownInt0, in, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( frequency, in, info );
		NifStream( startTime, in, info );
		NifStream( stopTime, in, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( unknownFloat2, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownByte, in, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( targetName, in, info );
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiControllerSequence::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiSequence::Write( out, link_map, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( weight, out, info );
		if ( textKeys != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(textKeys) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( cycleType, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownInt0, out, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( frequency, out, info );
		NifStream( startTime, out, info );
		NifStream( stopTime, out, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( unknownFloat2, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownByte, out, info );
	};
	if ( info.version >= 0x0A01006A ) {
		if ( manager != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(manager) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( targetName, out, info );
	};
	if ( info.version >= 0x0A020000 ) {
		if ( stringPalette != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(stringPalette) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiControllerSequence::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSequence::asString();
	out << "  Weight:  " << weight << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Cycle Type:  " << cycleType << endl;
	out << "  Unknown Int 0:  " << unknownInt0 << endl;
	out << "  Frequency:  " << frequency << endl;
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Manager:  " << manager << endl;
	out << "  Target Name:  " << targetName << endl;
	out << "  String Palette:  " << stringPalette << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiControllerSequence::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiSequence::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, info );
		manager = FixLink<NiControllerManager>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A020000 ) {
		stringPalette = FixLink<NiStringPalette>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiControllerSequence::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSequence::GetRefs();
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
	if ( stringPalette != NULL )
		refs.push_back(StaticCast<NiObject>(stringPalette));
	return refs;
}

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
