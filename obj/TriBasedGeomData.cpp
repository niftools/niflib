/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "TriBasedGeomData.h"

//Definition of TYPE constant
const Type TriBasedGeomData::TYPE("TriBasedGeomData", &TRI_BASED_GEOM_DATA_PARENT::TYPE );

TriBasedGeomData::TriBasedGeomData() TRI_BASED_GEOM_DATA_CONSTRUCT {}

TriBasedGeomData::~TriBasedGeomData() {}

void TriBasedGeomData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	TRI_BASED_GEOM_DATA_READ
}

void TriBasedGeomData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	TRI_BASED_GEOM_DATA_WRITE
}

string TriBasedGeomData::asString( bool verbose ) const {
	TRI_BASED_GEOM_DATA_STRING
}

void TriBasedGeomData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	TRI_BASED_GEOM_DATA_FIXLINKS
}

Vector3 TriBasedGeomData::Center() const { return Vector3(); }

float TriBasedGeomData::Radius() const { return 0.0f; }

