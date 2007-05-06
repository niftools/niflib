/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiScreenLODData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiScreenLODData::TYPE("NiScreenLODData", &NI_SCREEN_L_O_D_DATA_PARENT::TYPE );

NiScreenLODData::NiScreenLODData() NI_SCREEN_L_O_D_DATA_CONSTRUCT {}

NiScreenLODData::~NiScreenLODData() {}

void NiScreenLODData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiScreenLODData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiScreenLODData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiScreenLODData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiScreenLODData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiScreenLODData::GetType() const {
	return TYPE;
};

Vector3 NiScreenLODData::GetBoundCenter() const {
	return boundCenter;
}

void NiScreenLODData::SetBoundCenter( const Vector3 & value ) {
	boundCenter = value;
}

float NiScreenLODData::GetBoundRadius() const {
	return boundRadius;
}

void NiScreenLODData::SetBoundRadius( float value ) {
	boundRadius = value;
}

Vector3 NiScreenLODData::GetWorldCenter() const {
	return worldCenter;
}

void NiScreenLODData::SetWorldCenter( const Vector3 & value ) {
	worldCenter = value;
}

float NiScreenLODData::GetWorldRadius() const {
	return worldRadius;
}

void NiScreenLODData::SetWorldRadius( float value ) {
	worldRadius = value;
}

vector<float > NiScreenLODData::GetProportionLevels() const {
	return proportionLevels;
}

void NiScreenLODData::SetProportionLevels( const vector<float >& value ) {
	proportionLevels = value;
}

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiScreenLODData"] = NiScreenLODData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiScreenLODData::Create() {
	return new NiScreenLODData;
}
