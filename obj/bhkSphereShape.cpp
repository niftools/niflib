/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkSphereShape.h"

//Definition of TYPE constant
const Type bhkSphereShape::TYPE("bhkSphereShape", &BHK_SPHERE_SHAPE_PARENT::TypeConst() );

bhkSphereShape::bhkSphereShape() BHK_SPHERE_SHAPE_CONSTRUCT {}

bhkSphereShape::~bhkSphereShape() {}

void bhkSphereShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_SPHERE_SHAPE_READ
}

void bhkSphereShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_SPHERE_SHAPE_WRITE
}

string bhkSphereShape::asString( bool verbose ) const {
	BHK_SPHERE_SHAPE_STRING
}

void bhkSphereShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_SPHERE_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkSphereShape::GetRefs() const {
	BHK_SPHERE_SHAPE_GETREFS
}

const Type & bhkSphereShape::GetType() const {
	return TYPE;
};

