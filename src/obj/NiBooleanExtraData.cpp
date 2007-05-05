/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBooleanExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBooleanExtraData::TYPE("NiBooleanExtraData", &NI_BOOLEAN_EXTRA_DATA_PARENT::TYPE );

NiBooleanExtraData::NiBooleanExtraData() NI_BOOLEAN_EXTRA_DATA_CONSTRUCT {}

NiBooleanExtraData::~NiBooleanExtraData() {}

void NiBooleanExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBooleanExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBooleanExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBooleanExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBooleanExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBooleanExtraData::GetType() const {
	return TYPE;
};

bool NiBooleanExtraData::GetData() const {
	return (booleanData != 0);
}

void NiBooleanExtraData::SetData( bool n ) {
	booleanData = n;
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
		global_object_map["NiBooleanExtraData"] = NiBooleanExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBooleanExtraData::Create() {
	return new NiBooleanExtraData;
}
