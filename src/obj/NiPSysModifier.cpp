/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysModifier.h"
#include "../../include/obj/NiParticleSystem.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysModifier::TYPE("NiPSysModifier", &NI_P_SYS_MODIFIER_PARENT::TYPE );

NiPSysModifier::NiPSysModifier() NI_P_SYS_MODIFIER_CONSTRUCT {}

NiPSysModifier::~NiPSysModifier() {}

void NiPSysModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysModifier::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysModifier::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysModifier::GetType() const {
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
		global_object_map["NiPSysModifier"] = NiPSysModifier::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPSysModifier::Create() {
	return new NiPSysModifier;
}
