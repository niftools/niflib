/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkMultiSphereShape.h"
#include "../../include/gen/Sphere.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMultiSphereShape::TYPE("bhkMultiSphereShape", &BHK_MULTI_SPHERE_SHAPE_PARENT::TypeConst() );

bhkMultiSphereShape::bhkMultiSphereShape() BHK_MULTI_SPHERE_SHAPE_CONSTRUCT {}

bhkMultiSphereShape::~bhkMultiSphereShape() {}

void bhkMultiSphereShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_MULTI_SPHERE_SHAPE_READ
}

void bhkMultiSphereShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_MULTI_SPHERE_SHAPE_WRITE
}

string bhkMultiSphereShape::asString( bool verbose ) const {
	BHK_MULTI_SPHERE_SHAPE_STRING
}

void bhkMultiSphereShape::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_MULTI_SPHERE_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkMultiSphereShape::GetRefs() const {
	BHK_MULTI_SPHERE_SHAPE_GETREFS
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

