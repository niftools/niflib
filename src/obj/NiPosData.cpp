/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiPosData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPosData::TYPE("NiPosData", &NI_POS_DATA_PARENT::TYPE );

NiPosData::NiPosData() NI_POS_DATA_CONSTRUCT {}

NiPosData::~NiPosData() {}

void NiPosData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPosData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPosData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPosData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPosData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPosData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

KeyType NiPosData::GetKeyType() const {
	return data.interpolation;
}

void NiPosData::SetKeyType( KeyType t ) {
	data.interpolation = t;
}

vector< Key<Vector3> > NiPosData::GetKeys() const {
	return data.keys;
}

void NiPosData::SetKeys( vector< Key<Vector3> > const & keys ) {
	data.keys = keys;
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
		global_object_map["NiPosData"] = NiPosData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPosData::Create() {
	return new NiPosData;
}
