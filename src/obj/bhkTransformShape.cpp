/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkTransformShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkTransformShape::TYPE("bhkTransformShape", &BHK_TRANSFORM_SHAPE_PARENT::TypeConst() );

bhkTransformShape::bhkTransformShape() BHK_TRANSFORM_SHAPE_CONSTRUCT {}

bhkTransformShape::~bhkTransformShape() {}

void bhkTransformShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkTransformShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkTransformShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkTransformShape::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkTransformShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkTransformShape::GetType() const {
	return TYPE;
};

