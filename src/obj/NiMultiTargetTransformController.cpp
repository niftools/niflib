/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMultiTargetTransformController.h"
#include "../../include/obj/NiNode.h"
#include <algorithm>
using namespace Niflib;

//Definition of TYPE constant
const Type NiMultiTargetTransformController::TYPE("NiMultiTargetTransformController", &NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT::TypeConst() );

NiMultiTargetTransformController::NiMultiTargetTransformController() NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT {}

NiMultiTargetTransformController::~NiMultiTargetTransformController() {}

void NiMultiTargetTransformController::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiMultiTargetTransformController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiMultiTargetTransformController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMultiTargetTransformController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiMultiTargetTransformController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMultiTargetTransformController::GetType() const {
	return TYPE;
};

vector<NiNodeRef> NiMultiTargetTransformController::GetExtraTargets() const {
   vector<NiNodeRef> retval;
   size_t n = extraTargets.size();
   retval.reserve(n);
   for (size_t i=0; i<n; ++i)
      retval.push_back( NiNodeRef(extraTargets[i]) );
	return retval;
}

void NiMultiTargetTransformController::SetExtraTargets( const vector<NiNodeRef>& value ) {
   extraTargets.clear();
   size_t n = value.size();
   extraTargets.reserve(n);
   for (size_t i=0; i<n; ++i)
      extraTargets.push_back( value[i].Ptr() );
   extraTargets.erase(std::remove(extraTargets.begin(), extraTargets.end(), (NiNode*)NULL), extraTargets.end());
}

const Type & NiMultiTargetTransformController::TypeConst() {
	return TYPE;
}
