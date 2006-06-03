/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkSimpleShapePhantom.h"

//Definition of TYPE constant
const Type bhkSimpleShapePhantom::TYPE("bhkSimpleShapePhantom", &BHK_SIMPLE_SHAPE_PHANTOM_PARENT::TYPE );

bhkSimpleShapePhantom::bhkSimpleShapePhantom() BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT {}

bhkSimpleShapePhantom::~bhkSimpleShapePhantom() {}

void bhkSimpleShapePhantom::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	BHK_SIMPLE_SHAPE_PHANTOM_READ
}

void bhkSimpleShapePhantom::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	BHK_SIMPLE_SHAPE_PHANTOM_WRITE
}

string bhkSimpleShapePhantom::asString( bool verbose ) const {
	BHK_SIMPLE_SHAPE_PHANTOM_STRING
}

void bhkSimpleShapePhantom::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	BHK_SIMPLE_SHAPE_PHANTOM_FIXLINKS
}

const Type & bhkSimpleShapePhantom::GetType() const {
	return TYPE;
};

