/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiVertWeightsExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiVertWeightsExtraData::TYPE("NiVertWeightsExtraData", &NI_VERT_WEIGHTS_EXTRA_DATA_PARENT::TYPE );

NiVertWeightsExtraData::NiVertWeightsExtraData() NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT {}

NiVertWeightsExtraData::~NiVertWeightsExtraData() {}

void NiVertWeightsExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiVertWeightsExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiVertWeightsExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiVertWeightsExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiVertWeightsExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiVertWeightsExtraData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

vector<float> NiVertWeightsExtraData::GetData() const {
	return weight;
}
	
void NiVertWeightsExtraData::SetData( const vector<float> & n ) {
	numVertices = (unsigned int)(n.size());
	numBytes = numVertices + 2;
	weight = n;
}

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
		global_object_map["NiVertWeightsExtraData"] = NiVertWeightsExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiVertWeightsExtraData::Create() {
	return new NiVertWeightsExtraData;
}
