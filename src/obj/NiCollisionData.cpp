/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiCollisionData.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionData::TYPE("NiCollisionData", &NI_COLLISION_DATA_PARENT::TypeConst() );

NiCollisionData::NiCollisionData() NI_COLLISION_DATA_CONSTRUCT {}

NiCollisionData::~NiCollisionData() {}

void NiCollisionData::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiCollisionData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiCollisionData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiCollisionData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiCollisionData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiCollisionData::GetType() const {
	return TYPE;
};

