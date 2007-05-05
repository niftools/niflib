/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysColorModifier.h"
#include "../../include/obj/NiColorData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysColorModifier::TYPE("NiPSysColorModifier", &NI_P_SYS_COLOR_MODIFIER_PARENT::TYPE );

NiPSysColorModifier::NiPSysColorModifier() NI_P_SYS_COLOR_MODIFIER_CONSTRUCT {}

NiPSysColorModifier::~NiPSysColorModifier() {}

void NiPSysColorModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysColorModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysColorModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysColorModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysColorModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysColorModifier::GetType() const {
	return TYPE;
};

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiPSysColorModifier"] = NiPSysColorModifier::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPSysColorModifier::Create() {
	return new NiPSysColorModifier;
}
