/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkCapsuleShape.h"

//Definition of TYPE constant
const Type bhkCapsuleShape::TYPE("bhkCapsuleShape", &BHK_CAPSULE_SHAPE_PARENT::TYPE );

bhkCapsuleShape::bhkCapsuleShape() BHK_CAPSULE_SHAPE_CONSTRUCT {}

bhkCapsuleShape::~bhkCapsuleShape() {}

void bhkCapsuleShape::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	BHK_CAPSULE_SHAPE_READ
}

void bhkCapsuleShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_CAPSULE_SHAPE_WRITE
}

string bhkCapsuleShape::asString( bool verbose ) const {
	BHK_CAPSULE_SHAPE_STRING
}

void bhkCapsuleShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	BHK_CAPSULE_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkCapsuleShape::GetRefs() const {
	BHK_CAPSULE_SHAPE_GETREFS
}

const Type & bhkCapsuleShape::GetType() const {
	return TYPE;
};

