/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriShapeData.h"
#include "../gen/MatchGroup.h"

//Definition of TYPE constant
const Type NiTriShapeData::TYPE("NiTriShapeData", &NI_TRI_SHAPE_DATA_PARENT::TYPE );

NiTriShapeData::NiTriShapeData() NI_TRI_SHAPE_DATA_CONSTRUCT {}

NiTriShapeData::~NiTriShapeData() {}

void NiTriShapeData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_SHAPE_DATA_READ
}

void NiTriShapeData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRI_SHAPE_DATA_WRITE
}

string NiTriShapeData::asString( bool verbose ) const {
	NI_TRI_SHAPE_DATA_STRING
}

void NiTriShapeData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_SHAPE_DATA_FIXLINKS
}

list<NiObjectRef> NiTriShapeData::GetRefs() const {
	NI_TRI_SHAPE_DATA_GETREFS
}

const Type & NiTriShapeData::GetType() const {
	return TYPE;
};

