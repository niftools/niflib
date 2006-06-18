/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkConvexTransformShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkConvexTransformShape::TYPE("bhkConvexTransformShape", &BHK_CONVEX_TRANSFORM_SHAPE_PARENT::TypeConst() );

bhkConvexTransformShape::bhkConvexTransformShape() BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT {}

bhkConvexTransformShape::~bhkConvexTransformShape() {}

void bhkConvexTransformShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_CONVEX_TRANSFORM_SHAPE_READ
}

void bhkConvexTransformShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_CONVEX_TRANSFORM_SHAPE_WRITE
}

string bhkConvexTransformShape::asString( bool verbose ) const {
	BHK_CONVEX_TRANSFORM_SHAPE_STRING
}

void bhkConvexTransformShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_CONVEX_TRANSFORM_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkConvexTransformShape::GetRefs() const {
	BHK_CONVEX_TRANSFORM_SHAPE_GETREFS
}

const Type & bhkConvexTransformShape::GetType() const {
	return TYPE;
};

