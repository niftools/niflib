/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkListShape.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkListShape::TYPE("bhkListShape", &BHK_LIST_SHAPE_PARENT::TYPE );

bhkListShape::bhkListShape() BHK_LIST_SHAPE_CONSTRUCT {}

bhkListShape::~bhkListShape() {}

void bhkListShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkListShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkListShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkListShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkListShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkListShape::GetType() const {
	return TYPE;
};
