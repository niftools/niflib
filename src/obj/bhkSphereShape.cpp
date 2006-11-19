/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSphereShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSphereShape::TYPE("bhkSphereShape", &BHK_SPHERE_SHAPE_PARENT::TypeConst() );

bhkSphereShape::bhkSphereShape() BHK_SPHERE_SHAPE_CONSTRUCT {}

bhkSphereShape::~bhkSphereShape() {}

void bhkSphereShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkSphereShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkSphereShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSphereShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

