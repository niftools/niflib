/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiIntegerExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiIntegerExtraData::TYPE("NiIntegerExtraData", &NI_INTEGER_EXTRA_DATA_PARENT::TYPE );

NiIntegerExtraData::NiIntegerExtraData() NI_INTEGER_EXTRA_DATA_CONSTRUCT {}

NiIntegerExtraData::~NiIntegerExtraData() {}

void NiIntegerExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiIntegerExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiIntegerExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiIntegerExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiIntegerExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiIntegerExtraData::GetType() const {
	return TYPE;
};

unsigned int NiIntegerExtraData::GetData() const {
	return integerData;
}
	
void NiIntegerExtraData::SetData( unsigned int n ) {
	integerData = n;
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
		global_object_map["NiIntegerExtraData"] = NiIntegerExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiIntegerExtraData::Create() {
	return new NiIntegerExtraData;
}
