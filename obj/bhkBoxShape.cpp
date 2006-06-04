/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkBoxShape.h"

//Definition of TYPE constant
const Type bhkBoxShape::TYPE("bhkBoxShape", &BHK_BOX_SHAPE_PARENT::TYPE );

bhkBoxShape::bhkBoxShape() BHK_BOX_SHAPE_CONSTRUCT {}

bhkBoxShape::~bhkBoxShape() {}

void bhkBoxShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_BOX_SHAPE_READ
}

void bhkBoxShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_BOX_SHAPE_WRITE
}

string bhkBoxShape::asString( bool verbose ) const {
	BHK_BOX_SHAPE_STRING
}

void bhkBoxShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_BOX_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkBoxShape::GetRefs() const {
	BHK_BOX_SHAPE_GETREFS
}

const Type & bhkBoxShape::GetType() const {
	return TYPE;
};

