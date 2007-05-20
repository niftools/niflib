/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiDynamicEffect.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDynamicEffect::TYPE("NiDynamicEffect", &NI_DYNAMIC_EFFECT_PARENT::TYPE );

NiDynamicEffect::NiDynamicEffect() NI_DYNAMIC_EFFECT_CONSTRUCT {}

NiDynamicEffect::~NiDynamicEffect() {}

void NiDynamicEffect::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiDynamicEffect::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiDynamicEffect::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiDynamicEffect::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiDynamicEffect::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiDynamicEffect::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

bool NiDynamicEffect::GetSwitchState() const {
	return switchState;
}

void NiDynamicEffect::SetSwitchState( bool value ) {
	switchState = value;
}

vector<Ref<NiAVObject > > NiDynamicEffect::GetAffectedNodes() const {
	return affectedNodes;
}

void NiDynamicEffect::SetAffectedNodes( const vector<Ref<NiAVObject > >& value ) {
	affectedNodes = value;
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
		global_object_map["NiDynamicEffect"] = NiDynamicEffect::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiDynamicEffect::Create() {
	return new NiDynamicEffect;
}
