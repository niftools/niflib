/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiTriShape.h"

//Definition of TYPE constant
const Type NiTriShape::TYPE("NiTriShape", &NI_TRI_SHAPE_PARENT::TYPE );

NiTriShape::NiTriShape() NI_TRI_SHAPE_CONSTRUCT {}

NiTriShape::~NiTriShape() {}

void NiTriShape::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_TRI_SHAPE_READ
}

void NiTriShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TRI_SHAPE_WRITE
}

string NiTriShape::asString( bool verbose ) const {
	NI_TRI_SHAPE_STRING
}

void NiTriShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_TRI_SHAPE_FIXLINKS
}

list<NiObjectRef> NiTriShape::GetRefs() const {
	NI_TRI_SHAPE_GETREFS
}

const Type & NiTriShape::GetType() const {
	return TYPE;
};

