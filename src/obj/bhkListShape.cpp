/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkListShape.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkListShape::TYPE("bhkListShape", &BHK_LIST_SHAPE_PARENT::TypeConst() );

bhkListShape::bhkListShape() BHK_LIST_SHAPE_CONSTRUCT {}

bhkListShape::~bhkListShape() {}

void bhkListShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_LIST_SHAPE_READ
}

void bhkListShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_LIST_SHAPE_WRITE
}

string bhkListShape::asString( bool verbose ) const {
	BHK_LIST_SHAPE_STRING
}

void bhkListShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_LIST_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkListShape::GetRefs() const {
	BHK_LIST_SHAPE_GETREFS
}

const Type & bhkListShape::GetType() const {
	return TYPE;
};

