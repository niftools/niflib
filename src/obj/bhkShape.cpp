/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkShape::TYPE("bhkShape", &BHK_SHAPE_PARENT::TYPE );

bhkShape::bhkShape() BHK_SHAPE_CONSTRUCT {}

bhkShape::~bhkShape() {}

void bhkShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkShape::GetType() const {
	return TYPE;
};
