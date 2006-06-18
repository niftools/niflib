/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkSphereRepShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSphereRepShape::TYPE("bhkSphereRepShape", &BHK_SPHERE_REP_SHAPE_PARENT::TypeConst() );

bhkSphereRepShape::bhkSphereRepShape() BHK_SPHERE_REP_SHAPE_CONSTRUCT {}

bhkSphereRepShape::~bhkSphereRepShape() {}

void bhkSphereRepShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_SPHERE_REP_SHAPE_READ
}

void bhkSphereRepShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_SPHERE_REP_SHAPE_WRITE
}

string bhkSphereRepShape::asString( bool verbose ) const {
	BHK_SPHERE_REP_SHAPE_STRING
}

void bhkSphereRepShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_SPHERE_REP_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkSphereRepShape::GetRefs() const {
	BHK_SPHERE_REP_SHAPE_GETREFS
}

const Type & bhkSphereRepShape::GetType() const {
	return TYPE;
};

