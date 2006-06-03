/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiCollisionData.h"
#include "obj/NiNode.h"

//Definition of TYPE constant
const Type NiCollisionData::TYPE("NiCollisionData", &NI_COLLISION_DATA_PARENT::TYPE );

NiCollisionData::NiCollisionData() NI_COLLISION_DATA_CONSTRUCT {}

NiCollisionData::~NiCollisionData() {}

void NiCollisionData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_COLLISION_DATA_READ
}

void NiCollisionData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_COLLISION_DATA_WRITE
}

string NiCollisionData::asString( bool verbose ) const {
	NI_COLLISION_DATA_STRING
}

void NiCollisionData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_COLLISION_DATA_FIXLINKS
}

const Type & NiCollisionData::GetType() const {
	return TYPE;
};

