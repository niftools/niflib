/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiBlendFloatInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendFloatInterpolator::TYPE("NiBlendFloatInterpolator", &NI_BLEND_FLOAT_INTERPOLATOR_PARENT::TYPE );

NiBlendFloatInterpolator::NiBlendFloatInterpolator() NI_BLEND_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiBlendFloatInterpolator::~NiBlendFloatInterpolator() {}

void NiBlendFloatInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBlendFloatInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBlendFloatInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendFloatInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBlendFloatInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendFloatInterpolator::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

float NiBlendFloatInterpolator::GetFloatValue() const {
	return floatValue;
}

void NiBlendFloatInterpolator::SetFloatValue( float value ) {
	floatValue = value;
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
		global_object_map["NiBlendFloatInterpolator"] = NiBlendFloatInterpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBlendFloatInterpolator::Create() {
	return new NiBlendFloatInterpolator;
}
