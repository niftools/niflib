/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkListShape.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkListShape::TYPE("bhkListShape", &BHK_LIST_SHAPE_PARENT::TypeConst() );

bhkListShape::bhkListShape() BHK_LIST_SHAPE_CONSTRUCT {}

bhkListShape::~bhkListShape() {}

void bhkListShape::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkListShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkListShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkListShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkListShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkListShape::GetType() const {
	return TYPE;
};

const Type & bhkListShape::TypeConst() {
	return TYPE;
}
