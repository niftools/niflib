/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiVectorExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVectorExtraData::TYPE("NiVectorExtraData", &NI_VECTOR_EXTRA_DATA_PARENT::TYPE );

NiVectorExtraData::NiVectorExtraData() NI_VECTOR_EXTRA_DATA_CONSTRUCT {}

NiVectorExtraData::~NiVectorExtraData() {}

void NiVectorExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiVectorExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiVectorExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVectorExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiVectorExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVectorExtraData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

Vector3 NiVectorExtraData::GetData() const {
	return vectorData;
};
	
void NiVectorExtraData::SetData( const Vector3 & n ) {
	vectorData = n;
};

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiVectorExtraData"] = NiVectorExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiVectorExtraData::Create() {
	return new NiVectorExtraData;
}
