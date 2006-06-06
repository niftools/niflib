/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriBasedGeomData.h"
#include "NiObject.h"

//Definition of TYPE constant
const Type NiTriBasedGeomData::TYPE("NiTriBasedGeomData", &NI_TRI_BASED_GEOM_DATA_PARENT::TYPE );

NiTriBasedGeomData::NiTriBasedGeomData() NI_TRI_BASED_GEOM_DATA_CONSTRUCT {}

NiTriBasedGeomData::~NiTriBasedGeomData() {}

void NiTriBasedGeomData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_BASED_GEOM_DATA_READ
}

void NiTriBasedGeomData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRI_BASED_GEOM_DATA_WRITE
}

string NiTriBasedGeomData::asString( bool verbose ) const {
	NI_TRI_BASED_GEOM_DATA_STRING
}

void NiTriBasedGeomData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_BASED_GEOM_DATA_FIXLINKS
}

list<NiObjectRef> NiTriBasedGeomData::GetRefs() const {
	NI_TRI_BASED_GEOM_DATA_GETREFS
}

const Type & NiTriBasedGeomData::GetType() const {
	return TYPE;
};

void NiTriBasedGeomData::CalcCentAndRad( Vector3 & center, float & radius ) const {
	//Check if there are no vertices
	if ( vertices.size() == 0 ) {
		center.Set(0.0f, 0.0f, 0.0f);
		radius = 0.0f;
		return;
	}
	
	//Set lows and highs to first vertex
	Vector3 lows = vertices[0];
	Vector3 highs = vertices[0];

	//Iterate through the rest of the vertices, adjusting the stored values
	//if a vertex with lower or higher values is found
	for (vector<Vector3>::const_iterator i = vertices.begin()+1; i != vertices.end(); ++i ) {
		if ( i->x > highs.x ) highs.x = i->x;
		else if ( i->x < lows.x ) lows.x = i->x;

		if ( i->y > highs.y ) highs.y = i->y;
		else if ( i->y < lows.y ) lows.y = i->y;

		if ( i->z > highs.z ) highs.z = i->z;
		else if ( i->z < lows.z ) lows.z = i->z;
	}

	//Now we know the extent of the shape, so the center will be the average of the lows and highs.
	center.x = (highs.x + lows.x) / 2.0f;
	center.y = (highs.y + lows.y) / 2.0f;
	center.z = (highs.z + lows.z) / 2.0f;

	//The radius will be the largest distance from the center
	Vector3 diff;
	float dist2(0.0f), maxdist2(0.0f);
	for (vector<Vector3>::const_iterator i = vertices.begin(); i != vertices.end(); ++i ) {
		diff = center;
		diff.x -= i->x;
		diff.y -= i->y;
		diff.z -= i->z;
		dist2 = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
		if ( dist2 > maxdist2 ) maxdist2 = dist2;
	};
	radius = sqrt(maxdist2);
}

void NiTriBasedGeomData::SetVertexCount(int n) {
	if ( n > 65535 || n < 0 )
		throw runtime_error("Invalid Vertex Count: must be between 0 and 65535.");

	if ( n == 0 ) {
		vertices.clear();
		normals.clear();
		vertexColors.clear();
		for (uint i = 0; i < uvSets.size(); ++i) {
			uvSets[i].clear();
		}
		return;
	}
	
	//n != 0
	vertices.resize(n);

	if ( normals.size() != 0 ) { 
		normals.resize(n);
	}
	if ( vertexColors.size() != 0 ) {
		vertexColors.resize(n);
	}
	for (uint i = 0; i < uvSets.size(); ++i) {	
		uvSets[i].resize(n);
	}
}

void NiTriBasedGeomData::SetUVSetCount(int n) {
	uvSets.resize(n);
}

//--Setters--//
void NiTriBasedGeomData::SetVertices( const vector<Vector3> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.  Call SetVertexCount() to resize.");
	vertices = in;
}

void NiTriBasedGeomData::SetNormals( const vector<Vector3> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.  Call SetVertexCount() to resize.");
	normals = in;
}

void NiTriBasedGeomData::SetVertexColors( const vector<Color4> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.  Call SetVertexCount() to resize.");
	vertexColors = in;
}

void NiTriBasedGeomData::SetUVSet( int index, const vector<TexCoord> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Vector size must equal Vertex Count.  Call SetVertexCount() to resize.");
	uvSets[index] = in;
}

Vector3 NiTriBasedGeomData::Center() const { return Vector3(); }
float NiTriBasedGeomData::Radius() const { return float(); }
