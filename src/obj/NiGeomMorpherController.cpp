/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiGeomMorpherController.h"
#include "../../include/obj/NiMorphData.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiGeomMorpherController::TYPE("NiGeomMorpherController", &NI_GEOM_MORPHER_CONTROLLER_PARENT::TYPE );

NiGeomMorpherController::NiGeomMorpherController() NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT {}

NiGeomMorpherController::~NiGeomMorpherController() {}

void NiGeomMorpherController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiGeomMorpherController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiGeomMorpherController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiGeomMorpherController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiGeomMorpherController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiGeomMorpherController::GetType() const {
	return TYPE;
};

vector< Ref<NiInterpolator> > NiGeomMorpherController::GetInterpolators() const {
	return interpolators;
}

void NiGeomMorpherController::SetInterpolators( const vector< Ref<NiInterpolator> > & n ) {
	numInterpolators = (unsigned int)(n.size());
	interpolators = n;
}

Ref<NiMorphData> NiGeomMorpherController::GetData() const {
	return data;
}

void NiGeomMorpherController::SetData( NiMorphData * n ) {
	data = n;
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
		global_object_map["NiGeomMorpherController"] = NiGeomMorpherController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiGeomMorpherController::Create() {
	return new NiGeomMorpherController;
}
