/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiRangeLODData.h"
#include "../../include/gen/LODRange.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRangeLODData::TYPE("NiRangeLODData", &NI_RANGE_L_O_D_DATA_PARENT::TYPE );

NiRangeLODData::NiRangeLODData() NI_RANGE_L_O_D_DATA_CONSTRUCT {}

NiRangeLODData::~NiRangeLODData() {}

void NiRangeLODData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiRangeLODData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiRangeLODData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiRangeLODData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiRangeLODData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiRangeLODData::GetType() const {
	return TYPE;
};

Vector3 NiRangeLODData::GetLODCenter() const {
	return lodCenter;
}

void NiRangeLODData::SetLODCenter( const Vector3 & value ) {
	lodCenter = value;
}

vector<LODRange > NiRangeLODData::GetLODLevels() const {
	return lodLevels;
}

void NiRangeLODData::SetLODLevels( const vector<LODRange >& value ) {
	lodLevels = value;
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
		global_object_map["NiRangeLODData"] = NiRangeLODData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiRangeLODData::Create() {
	return new NiRangeLODData;
}
