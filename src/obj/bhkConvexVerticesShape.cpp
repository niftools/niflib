/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkConvexVerticesShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkConvexVerticesShape::TYPE("bhkConvexVerticesShape", &BHK_CONVEX_VERTICES_SHAPE_PARENT::TypeConst() );

bhkConvexVerticesShape::bhkConvexVerticesShape() BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT {}

bhkConvexVerticesShape::~bhkConvexVerticesShape() {}

void bhkConvexVerticesShape::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkConvexVerticesShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkConvexVerticesShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkConvexVerticesShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkConvexVerticesShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkConvexVerticesShape::GetType() const {
	return TYPE;
};

const Type & bhkConvexVerticesShape::TypeConst() {
	return TYPE;
}
