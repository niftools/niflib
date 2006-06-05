/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkTransformShape.h"

//Definition of TYPE constant
const Type bhkTransformShape::TYPE("bhkTransformShape", &BHK_TRANSFORM_SHAPE_PARENT::TYPE );

bhkTransformShape::bhkTransformShape() BHK_TRANSFORM_SHAPE_CONSTRUCT {}

bhkTransformShape::~bhkTransformShape() {}

void bhkTransformShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_TRANSFORM_SHAPE_READ
}

void bhkTransformShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_TRANSFORM_SHAPE_WRITE
}

string bhkTransformShape::asString( bool verbose ) const {
	BHK_TRANSFORM_SHAPE_STRING
}

void bhkTransformShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_TRANSFORM_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkTransformShape::GetRefs() const {
	BHK_TRANSFORM_SHAPE_GETREFS
}

const Type & bhkTransformShape::GetType() const {
	return TYPE;
};

