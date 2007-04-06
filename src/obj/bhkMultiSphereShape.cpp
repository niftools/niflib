/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkMultiSphereShape.h"
#include "../../include/gen/Sphere.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMultiSphereShape::TYPE("bhkMultiSphereShape", &BHK_MULTI_SPHERE_SHAPE_PARENT::TypeConst() );

bhkMultiSphereShape::bhkMultiSphereShape() BHK_MULTI_SPHERE_SHAPE_CONSTRUCT {}

bhkMultiSphereShape::~bhkMultiSphereShape() {}

void bhkMultiSphereShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkMultiSphereShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkMultiSphereShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkMultiSphereShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkMultiSphereShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkMultiSphereShape::GetType() const {
	return TYPE;
};

vector<Sphere > bhkMultiSphereShape::GetSpheres() const {
	return spheres;
}

void bhkMultiSphereShape::SetSpheres( const vector<Sphere >& value ) {
	spheres = value;
}

const Type & bhkMultiSphereShape::TypeConst() {
	return TYPE;
}
