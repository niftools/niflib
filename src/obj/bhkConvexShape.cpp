/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkConvexShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkConvexShape::TYPE("bhkConvexShape", &BHK_CONVEX_SHAPE_PARENT::TYPE );

bhkConvexShape::bhkConvexShape() BHK_CONVEX_SHAPE_CONSTRUCT {}

bhkConvexShape::~bhkConvexShape() {}

void bhkConvexShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkConvexShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkConvexShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkConvexShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkConvexShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkConvexShape::GetType() const {
	return TYPE;
};
