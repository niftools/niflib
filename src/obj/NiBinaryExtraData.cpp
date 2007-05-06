/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiBinaryExtraData.h"
#include "../../include/gen/ByteArray.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBinaryExtraData::TYPE("NiBinaryExtraData", &NI_BINARY_EXTRA_DATA_PARENT::TYPE );

NiBinaryExtraData::NiBinaryExtraData() NI_BINARY_EXTRA_DATA_CONSTRUCT {}

NiBinaryExtraData::~NiBinaryExtraData() {}

void NiBinaryExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBinaryExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBinaryExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBinaryExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBinaryExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBinaryExtraData::GetType() const {
	return TYPE;
};


vector<byte> NiBinaryExtraData::GetData() const {
	return binaryData.data;
};

void NiBinaryExtraData::SetData( const vector<byte> & n ) {
	binaryData.dataSize = (unsigned int)(n.size());
	binaryData.data = n;
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
		global_object_map["NiBinaryExtraData"] = NiBinaryExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBinaryExtraData::Create() {
	return new NiBinaryExtraData;
}
