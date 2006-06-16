/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkPackedNiTriStripsShape.h"
#include "hkPackedNiTriStripsData.h"

//Definition of TYPE constant
const Type bhkPackedNiTriStripsShape::TYPE("bhkPackedNiTriStripsShape", &BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT::TypeConst() );

bhkPackedNiTriStripsShape::bhkPackedNiTriStripsShape() BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkPackedNiTriStripsShape::~bhkPackedNiTriStripsShape() {}

void bhkPackedNiTriStripsShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_READ
}

void bhkPackedNiTriStripsShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_WRITE
}

string bhkPackedNiTriStripsShape::asString( bool verbose ) const {
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_STRING
}

void bhkPackedNiTriStripsShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_FIXLINKS
}

list<NiObjectRef> bhkPackedNiTriStripsShape::GetRefs() const {
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_GETREFS
}

const Type & bhkPackedNiTriStripsShape::GetType() const {
	return TYPE;
};

