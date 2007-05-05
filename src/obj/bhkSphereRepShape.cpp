/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSphereRepShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSphereRepShape::TYPE("bhkSphereRepShape", &BHK_SPHERE_REP_SHAPE_PARENT::TYPE );

bhkSphereRepShape::bhkSphereRepShape() BHK_SPHERE_REP_SHAPE_CONSTRUCT {}

bhkSphereRepShape::~bhkSphereRepShape() {}

void bhkSphereRepShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkSphereRepShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkSphereRepShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSphereRepShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
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
