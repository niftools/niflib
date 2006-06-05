/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkConvexVerticesShape.h"

//Definition of TYPE constant
const Type bhkConvexVerticesShape::TYPE("bhkConvexVerticesShape", &BHK_CONVEX_VERTICES_SHAPE_PARENT::TYPE );

bhkConvexVerticesShape::bhkConvexVerticesShape() BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT {}

bhkConvexVerticesShape::~bhkConvexVerticesShape() {}

void bhkConvexVerticesShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_CONVEX_VERTICES_SHAPE_READ
}

void bhkConvexVerticesShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_CONVEX_VERTICES_SHAPE_WRITE
}

string bhkConvexVerticesShape::asString( bool verbose ) const {
	BHK_CONVEX_VERTICES_SHAPE_STRING
}

void bhkConvexVerticesShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_CONVEX_VERTICES_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkConvexVerticesShape::GetRefs() const {
	BHK_CONVEX_VERTICES_SHAPE_GETREFS
}

const Type & bhkConvexVerticesShape::GetType() const {
	return TYPE;
};

