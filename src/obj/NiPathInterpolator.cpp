/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPathInterpolator.h"
#include "../../include/obj/NiPosData.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPathInterpolator::TYPE("NiPathInterpolator", &NI_PATH_INTERPOLATOR_PARENT::TYPE );

NiPathInterpolator::NiPathInterpolator() NI_PATH_INTERPOLATOR_CONSTRUCT {}

NiPathInterpolator::~NiPathInterpolator() {}

void NiPathInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPathInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPathInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPathInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPathInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPathInterpolator::GetType() const {
	return TYPE;
};

Ref<NiPosData > NiPathInterpolator::GetPosData() const {
	return posData;
}

void NiPathInterpolator::SetPosData( NiPosData * value ) {
	posData = value;
}

Ref<NiFloatData > NiPathInterpolator::GetFloatData() const {
	return floatData;
}

void NiPathInterpolator::SetFloatData( NiFloatData * value ) {
	floatData = value;
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
		global_object_map["NiPathInterpolator"] = NiPathInterpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPathInterpolator::Create() {
	return new NiPathInterpolator;
}
