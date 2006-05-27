/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkConvexShape.h"

//Definition of TYPE constant
const Type bhkConvexShape::TYPE("bhkConvexShape", &BHK_CONVEX_SHAPE_PARENT::TYPE );

bhkConvexShape::bhkConvexShape() BHK_CONVEX_SHAPE_CONSTRUCT {}

bhkConvexShape::~bhkConvexShape() {}

void bhkConvexShape::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	BHK_CONVEX_SHAPE_READ
}

void bhkConvexShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_CONVEX_SHAPE_WRITE
}

string bhkConvexShape::asString( bool verbose ) const {
	BHK_CONVEX_SHAPE_STRING
}

void bhkConvexShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	BHK_CONVEX_SHAPE_FIXLINKS
}

