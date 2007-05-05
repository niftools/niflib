/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiColorData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiColorData::TYPE("NiColorData", &NI_COLOR_DATA_PARENT::TYPE );

NiColorData::NiColorData() NI_COLOR_DATA_CONSTRUCT {}

NiColorData::~NiColorData() {}

void NiColorData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiColorData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiColorData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiColorData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiColorData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiColorData::GetType() const {
	return TYPE;
};

KeyType NiColorData::GetKeyType() const {
	return data.interpolation;
}

void NiColorData::SetKeyType( KeyType t ) {
	data.interpolation = t;
}

vector< Key<Color4> > NiColorData::GetKeys() const {
	return data.keys;
}

void NiColorData::SetKeys( vector< Key<Color4> > const & keys ) {
	data.keys = keys;
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
		global_object_map["NiColorData"] = NiColorData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiColorData::Create() {
	return new NiColorData;
}
