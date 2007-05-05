/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatsExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatsExtraData::TYPE("NiFloatsExtraData", &NI_FLOATS_EXTRA_DATA_PARENT::TYPE );

NiFloatsExtraData::NiFloatsExtraData() NI_FLOATS_EXTRA_DATA_CONSTRUCT {}

NiFloatsExtraData::~NiFloatsExtraData() {}

void NiFloatsExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiFloatsExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiFloatsExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatsExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiFloatsExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatsExtraData::GetType() const {
	return TYPE;
};

vector<float> NiFloatsExtraData::GetData() const {
	return data;
}
	
void NiFloatsExtraData::SetData( const vector<float> & n ) {
	numFloats = (unsigned int)(n.size());
	data = n;
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
		global_object_map["NiFloatsExtraData"] = NiFloatsExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiFloatsExtraData::Create() {
	return new NiFloatsExtraData;
}
