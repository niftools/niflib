/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkMoppBvTreeShape.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMoppBvTreeShape::TYPE("bhkMoppBvTreeShape", &BHK_MOPP_BV_TREE_SHAPE_PARENT::TypeConst() );

bhkMoppBvTreeShape::bhkMoppBvTreeShape() BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT {}

bhkMoppBvTreeShape::~bhkMoppBvTreeShape() {}

void bhkMoppBvTreeShape::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkMoppBvTreeShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkMoppBvTreeShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkMoppBvTreeShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkMoppBvTreeShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkMoppBvTreeShape::GetType() const {
	return TYPE;
};

const Type & bhkMoppBvTreeShape::TypeConst() {
	return TYPE;
}
