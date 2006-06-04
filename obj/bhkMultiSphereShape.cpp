/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkMultiSphereShape.h"

//Definition of TYPE constant
const Type bhkMultiSphereShape::TYPE("bhkMultiSphereShape", &BHK_MULTI_SPHERE_SHAPE_PARENT::TYPE );

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

void bhkMultiSphereShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_MULTI_SPHERE_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkMultiSphereShape::GetRefs() const {
	BHK_MULTI_SPHERE_SHAPE_GETREFS
}

const Type & bhkMultiSphereShape::GetType() const {
	return TYPE;
};

