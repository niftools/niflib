/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSphereRepShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSphereRepShape::TYPE("bhkSphereRepShape", &BHK_SPHERE_REP_SHAPE_PARENT::TypeConst() );

bhkSphereRepShape::bhkSphereRepShape() BHK_SPHERE_REP_SHAPE_CONSTRUCT {}

bhkSphereRepShape::~bhkSphereRepShape() {}

void bhkSphereRepShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkSphereRepShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkSphereRepShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSphereRepShape::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkSphereRepShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSphereRepShape::GetType() const {
	return TYPE;
};

HavokMaterial bhkSphereRepShape::GetMaterial() const {
	return material;
}

void bhkSphereRepShape::SetMaterial( HavokMaterial value ) {
	material = value;
}

