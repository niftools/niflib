/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSphereShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSphereShape::TYPE("bhkSphereShape", &BHK_SPHERE_SHAPE_PARENT::TypeConst() );

bhkSphereShape::bhkSphereShape() BHK_SPHERE_SHAPE_CONSTRUCT {}

bhkSphereShape::~bhkSphereShape() {}

void bhkSphereShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkSphereShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkSphereShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSphereShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkSphereShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSphereShape::GetType() const {
	return TYPE;
};

float bhkSphereShape::GetRadius() const {
	return radius;
}

void bhkSphereShape::SetRadius( float value ) {
	radius = value;
}

const Type & bhkSphereShape::TypeConst() {
	return TYPE;
}
