/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTriShapeData.h"
#include "../../include/gen/MatchGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriShapeData::TYPE("NiTriShapeData", &NI_TRI_SHAPE_DATA_PARENT::TypeConst() );

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

void NiTriShapeData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_SHAPE_DATA_FIXLINKS
}

list<NiObjectRef> NiTriShapeData::GetRefs() const {
	NI_TRI_SHAPE_DATA_GETREFS
}

const Type & NiTriShapeData::GetType() const {
	return TYPE;
};

NiTriShapeData::NiTriShapeData(const vector<Triangle> &tris) {
   SetTriangles(tris);
}

void NiTriShapeData::SetVertices( const vector<Vector3> & in ) {
	//Take normal action
	NiTriBasedGeomData::SetVertices( in );

	//Also, clear match detection data
	matchGroups.clear();
}

void NiTriShapeData::DoMatchDetection() { 
	matchGroups.resize( vertices.size() );

	for ( uint i = 0; i < matchGroups.size(); ++i ){
		// Find all vertices that match this one.
		for ( ushort j = 0; j < vertices.size(); ++j ) {
			if ( vertices[i] == vertices[j] ) {
				matchGroups[i].vertexIndices.push_back(j);
			}
		}
	}
}

bool NiTriShapeData::HasMatchData() {
	return ( matchGroups.size() > 0 );
}

vector<Triangle> NiTriShapeData::GetTriangles() const {
	return triangles;
}

void NiTriShapeData::SetTriangles( const vector<Triangle> & in ) {
	if ( in.size() > 65535 || in.size() < 0 ) {
		throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
	}

	triangles = in;

	hasTriangles = ( triangles.size() != 0 );

	//Set number of trianble points to the number of triangles times 3
	numTrianglePoints = uint(triangles.size()) * 3;
}

