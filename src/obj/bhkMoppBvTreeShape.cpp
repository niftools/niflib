/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkMoppBvTreeShape.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMoppBvTreeShape::TYPE("bhkMoppBvTreeShape", &BHK_MOPP_BV_TREE_SHAPE_PARENT::TYPE );

bhkMoppBvTreeShape::bhkMoppBvTreeShape() BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT {}

bhkMoppBvTreeShape::~bhkMoppBvTreeShape() {}

void bhkMoppBvTreeShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkMoppBvTreeShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkMoppBvTreeShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkMoppBvTreeShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkMoppBvTreeShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkMoppBvTreeShape::GetType() const {
	return TYPE;
};
