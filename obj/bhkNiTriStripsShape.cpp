/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkNiTriStripsShape.h"

//Definition of TYPE constant
const Type bhkNiTriStripsShape::TYPE("bhkNiTriStripsShape", &BHK_NI_TRI_STRIPS_SHAPE_PARENT::TYPE );

bhkNiTriStripsShape::bhkNiTriStripsShape() BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkNiTriStripsShape::~bhkNiTriStripsShape() {}

void bhkNiTriStripsShape::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	BHK_NI_TRI_STRIPS_SHAPE_READ
}

void bhkNiTriStripsShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_NI_TRI_STRIPS_SHAPE_WRITE
}

string bhkNiTriStripsShape::asString( bool verbose ) const {
	BHK_NI_TRI_STRIPS_SHAPE_STRING
}

void bhkNiTriStripsShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	BHK_NI_TRI_STRIPS_SHAPE_FIXLINKS
}

const Type & bhkNiTriStripsShape::GetType() const {
	return TYPE;
};

