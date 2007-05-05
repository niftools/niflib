/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatExtraData::TYPE("NiFloatExtraData", &NI_FLOAT_EXTRA_DATA_PARENT::TYPE );

NiFloatExtraData::NiFloatExtraData() NI_FLOAT_EXTRA_DATA_CONSTRUCT {}

NiFloatExtraData::~NiFloatExtraData() {}

void NiFloatExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiFloatExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiFloatExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiFloatExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatExtraData::GetType() const {
	return TYPE;
};

float NiFloatExtraData::GetData() const {
	return floatData;
}
	
void NiFloatExtraData::SetData( float n ) {
	floatData = n;
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
		global_object_map["NiFloatExtraData"] = NiFloatExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiFloatExtraData::Create() {
	return new NiFloatExtraData;
}
