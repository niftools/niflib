/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoolTimelineInterpolator.h"
#include "../../include/obj/NiBoolData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoolTimelineInterpolator::TYPE("NiBoolTimelineInterpolator", &NI_BOOL_TIMELINE_INTERPOLATOR_PARENT::TYPE );

NiBoolTimelineInterpolator::NiBoolTimelineInterpolator() NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT {}

NiBoolTimelineInterpolator::~NiBoolTimelineInterpolator() {}

void NiBoolTimelineInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBoolTimelineInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBoolTimelineInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBoolTimelineInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBoolTimelineInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBoolTimelineInterpolator::GetType() const {
	return TYPE;
};

bool NiBoolTimelineInterpolator::GetBoolValue() const {
	return (boolValue != 0);
}

void NiBoolTimelineInterpolator::SetBoolValue( bool value ) {
	boolValue = value;
}

Ref<NiBoolData> NiBoolTimelineInterpolator::GetData() const {
	return data;
}

void NiBoolTimelineInterpolator::SetData( NiBoolData * value ) {
	data = value;
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
		global_object_map["NiBoolTimelineInterpolator"] = NiBoolTimelineInterpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBoolTimelineInterpolator::Create() {
	return new NiBoolTimelineInterpolator;
}
