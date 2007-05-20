/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiMultiTargetTransformController.h"
#include "../../include/obj/NiNode.h"
#include <algorithm>
using namespace Niflib;

//Definition of TYPE constant
const Type NiMultiTargetTransformController::TYPE("NiMultiTargetTransformController", &NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT::TYPE );

NiMultiTargetTransformController::NiMultiTargetTransformController() NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiMultiTargetTransformController::~NiMultiTargetTransformController() {}

void NiMultiTargetTransformController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiMultiTargetTransformController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiMultiTargetTransformController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMultiTargetTransformController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiMultiTargetTransformController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMultiTargetTransformController::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

vector<NiNodeRef> NiMultiTargetTransformController::GetExtraTargets() const {
   vector<NiNodeRef> retval;
   size_t n = extraTargets.size();
   retval.reserve(n);
   for (size_t i=0; i<n; ++i)
      retval.push_back( NiNodeRef(extraTargets[i]) );
	return retval;
}

void NiMultiTargetTransformController::SetExtraTargets( const vector< Ref<NiNode> > & value ) {
   extraTargets.clear();
   size_t n = value.size();
   extraTargets.reserve(n);
   for (size_t i=0; i<n; ++i)
      extraTargets.push_back( value[i] );
   extraTargets.erase(std::remove(extraTargets.begin(), extraTargets.end(), (NiNode*)NULL), extraTargets.end());
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
		global_object_map["NiMultiTargetTransformController"] = NiMultiTargetTransformController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiMultiTargetTransformController::Create() {
	return new NiMultiTargetTransformController;
}
