/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkNiTriStripsShape.h"
#include "NiTriStripsData.h"

//Definition of TYPE constant
const Type bhkNiTriStripsShape::TYPE("bhkNiTriStripsShape", &BHK_NI_TRI_STRIPS_SHAPE_PARENT::TypeConst() );

bhkNiTriStripsShape::bhkNiTriStripsShape() BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkNiTriStripsShape::~bhkNiTriStripsShape() {}

void bhkNiTriStripsShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_NI_TRI_STRIPS_SHAPE_READ
}

void bhkNiTriStripsShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_NI_TRI_STRIPS_SHAPE_WRITE
}

string bhkNiTriStripsShape::asString( bool verbose ) const {
	BHK_NI_TRI_STRIPS_SHAPE_STRING
}

void bhkNiTriStripsShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_NI_TRI_STRIPS_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkNiTriStripsShape::GetRefs() const {
	BHK_NI_TRI_STRIPS_SHAPE_GETREFS
}

const Type & bhkNiTriStripsShape::GetType() const {
	return TYPE;
};

