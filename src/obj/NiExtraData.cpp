/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiExtraData::TYPE("NiExtraData", &NI_EXTRA_DATA_PARENT::TYPE );

NiExtraData::NiExtraData() NI_EXTRA_DATA_CONSTRUCT {}

NiExtraData::~NiExtraData() {}

void NiExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiExtraData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

string NiExtraData::GetName() {
	return name;
}

void NiExtraData::SetName( const string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiExtraData::GetIDString() const {
	stringstream out;
	out << NiObject::GetIDString() << " {" << name << "}";
	return out.str();
}

NiExtraDataRef NiExtraData::GetNextExtraData() const {
	return nextExtraData;
}

void NiExtraData::SetNextExtraData( NiExtraData * obj ) {
	nextExtraData = obj;
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
		global_object_map["NiExtraData"] = NiExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiExtraData::Create() {
	return new NiExtraData;
}
