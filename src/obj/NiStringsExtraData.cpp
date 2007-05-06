/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiStringsExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringsExtraData::TYPE("NiStringsExtraData", &NI_STRINGS_EXTRA_DATA_PARENT::TYPE );

NiStringsExtraData::NiStringsExtraData() NI_STRINGS_EXTRA_DATA_CONSTRUCT {}

NiStringsExtraData::~NiStringsExtraData() {}

void NiStringsExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiStringsExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiStringsExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStringsExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiStringsExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiStringsExtraData::GetType() const {
	return TYPE;
};

vector<string> NiStringsExtraData::GetData() const {
	return data;
};
	
void NiStringsExtraData::SetData( const vector<string> & n ) {
	numStrings = (unsigned int)(n.size());
	data = n;
};

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiStringsExtraData"] = NiStringsExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiStringsExtraData::Create() {
	return new NiStringsExtraData;
}
