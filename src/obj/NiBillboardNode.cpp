/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBillboardNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBillboardNode::TYPE("NiBillboardNode", &NI_BILLBOARD_NODE_PARENT::TypeConst() );

NiBillboardNode::NiBillboardNode() NI_BILLBOARD_NODE_CONSTRUCT {}

NiBillboardNode::~NiBillboardNode() {}

void NiBillboardNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBillboardNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBillboardNode::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBillboardNode::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBillboardNode::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBillboardNode::GetType() const {
	return TYPE;
};

BillboardMode NiBillboardNode::GetBillboardMode() const {
	return billboardMode;
}

void NiBillboardNode::SetBillboardMode( BillboardMode value ) {
	billboardMode = value;
}

