/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiAVObjectPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAVObjectPalette::TYPE("NiAVObjectPalette", &NI_A_V_OBJECT_PALETTE_PARENT::TYPE );

NiAVObjectPalette::NiAVObjectPalette() NI_A_V_OBJECT_PALETTE_CONSTRUCT {}

NiAVObjectPalette::~NiAVObjectPalette() {}

void NiAVObjectPalette::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAVObjectPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAVObjectPalette::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAVObjectPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAVObjectPalette::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAVObjectPalette::GetType() const {
	return TYPE;
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
		global_object_map["NiAVObjectPalette"] = NiAVObjectPalette::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiAVObjectPalette::Create() {
	return new NiAVObjectPalette;
}

