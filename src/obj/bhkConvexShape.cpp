/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkConvexShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkConvexShape::TYPE("bhkConvexShape", &BHK_CONVEX_SHAPE_PARENT::TypeConst() );

bhkConvexShape::bhkConvexShape() BHK_CONVEX_SHAPE_CONSTRUCT {}

bhkConvexShape::~bhkConvexShape() {}

void bhkConvexShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkConvexShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkConvexShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkConvexShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkConvexShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkConvexShape::GetType() const {
	return TYPE;
};

