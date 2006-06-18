/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiCollisionData.h"
#include "NiNode.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiCollisionData::TYPE("NiCollisionData", &NI_COLLISION_DATA_PARENT::TypeConst() );

NiCollisionData::NiCollisionData() NI_COLLISION_DATA_CONSTRUCT {}

NiCollisionData::~NiCollisionData() {}

void NiCollisionData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_COLLISION_DATA_READ
}

void NiCollisionData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_COLLISION_DATA_WRITE
}

string NiCollisionData::asString( bool verbose ) const {
	NI_COLLISION_DATA_STRING
}

void NiCollisionData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_COLLISION_DATA_FIXLINKS
}

list<NiObjectRef> NiCollisionData::GetRefs() const {
	NI_COLLISION_DATA_GETREFS
}

const Type & NiCollisionData::GetType() const {
	return TYPE;
};

