/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiStringExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringExtraData::TYPE("NiStringExtraData", &NI_STRING_EXTRA_DATA_PARENT::TYPE );

NiStringExtraData::NiStringExtraData() NI_STRING_EXTRA_DATA_CONSTRUCT {}

NiStringExtraData::~NiStringExtraData() {}

void NiStringExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiStringExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiStringExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStringExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiStringExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiStringExtraData::GetType() const {
	return TYPE;
};

string NiStringExtraData::GetData() const {
	return stringData;
}

void NiStringExtraData::SetData( const string & n ) {
	stringData = n;
	bytesRemaining = (unsigned int)(stringData.size()) + 4;
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
		global_object_map["NiStringExtraData"] = NiStringExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiStringExtraData::Create() {
	return new NiStringExtraData;
}
