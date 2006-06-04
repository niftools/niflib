/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkEntity.h"
#include "obj/bhkShape.h"

//Definition of TYPE constant
const Type bhkEntity::TYPE("bhkEntity", &BHK_ENTITY_PARENT::TYPE );

bhkEntity::bhkEntity() BHK_ENTITY_CONSTRUCT {}

bhkEntity::~bhkEntity() {}

void bhkEntity::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	BHK_ENTITY_READ
}

void bhkEntity::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_ENTITY_WRITE
}

string bhkEntity::asString( bool verbose ) const {
	BHK_ENTITY_STRING
}

void bhkEntity::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	BHK_ENTITY_FIXLINKS
}

const Type & bhkEntity::GetType() const {
	return TYPE;
};

