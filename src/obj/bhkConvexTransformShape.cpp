/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkConvexTransformShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkConvexTransformShape::TYPE("bhkConvexTransformShape", &BHK_CONVEX_TRANSFORM_SHAPE_PARENT::TypeConst() );

bhkConvexTransformShape::bhkConvexTransformShape() BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT {}

bhkConvexTransformShape::~bhkConvexTransformShape() {}

void bhkConvexTransformShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkConvexTransformShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkConvexTransformShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkConvexTransformShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkConvexTransformShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkConvexTransformShape::GetType() const {
	return TYPE;
};

