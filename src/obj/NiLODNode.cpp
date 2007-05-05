/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLODNode.h"
#include "../../include/gen/LODRange.h"
#include "../../include/obj/NiRangeLODData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLODNode::TYPE("NiLODNode", &NI_L_O_D_NODE_PARENT::TYPE );

NiLODNode::NiLODNode() NI_L_O_D_NODE_CONSTRUCT {}

NiLODNode::~NiLODNode() {}

void NiLODNode::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiLODNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiLODNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLODNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiLODNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLODNode::GetType() const {
	return TYPE;
};

Vector3 NiLODNode::GetLODCenter() const {
	return lodCenter;
}

void NiLODNode::SetLODCenter( const Vector3 & value ) {
	lodCenter = value;
}

vector<LODRange > NiLODNode::GetLODLevels() const {
	return lodLevels;
}

void NiLODNode::SetLODLevels( const vector<LODRange >& value ) {
	lodLevels = value;
}

Ref<NiLODData > NiLODNode::GetLODLevelData() const {
	return lodLevelData;
}

void NiLODNode::SetLODLevelData( Ref<NiLODData > value ) {
	lodLevelData = value;
}
