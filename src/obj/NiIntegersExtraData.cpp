/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiIntegersExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiIntegersExtraData::TYPE("NiIntegersExtraData", &NI_INTEGERS_EXTRA_DATA_PARENT::TYPE );

NiIntegersExtraData::NiIntegersExtraData() NI_INTEGERS_EXTRA_DATA_CONSTRUCT {}

NiIntegersExtraData::~NiIntegersExtraData() {}

void NiIntegersExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiIntegersExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiIntegersExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiIntegersExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiIntegersExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiIntegersExtraData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

vector<unsigned int> NiIntegersExtraData::GetData() const {
	return data;
};
	
void NiIntegersExtraData::SetData( const vector<unsigned int> & n ) {
	numIntegers = (unsigned int)( n.size() );
	data = n;
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
		global_object_map["NiIntegersExtraData"] = NiIntegersExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiIntegersExtraData::Create() {
	return new NiIntegersExtraData;
}
