/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkTransformShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkTransformShape::TYPE("bhkTransformShape", &BHK_TRANSFORM_SHAPE_PARENT::TypeConst() );

bhkTransformShape::bhkTransformShape() BHK_TRANSFORM_SHAPE_CONSTRUCT {}

bhkTransformShape::~bhkTransformShape() {}

void bhkTransformShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkTransformShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkTransformShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkTransformShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkTransformShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkTransformShape::GetType() const {
	return TYPE;
};

const Type & bhkTransformShape::TypeConst() {
	return TYPE;
}
