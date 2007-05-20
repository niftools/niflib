/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiGeometryData.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiGeometryData::TYPE("NiGeometryData", &NI_GEOMETRY_DATA_PARENT::TYPE );

NiGeometryData::NiGeometryData() NI_GEOMETRY_DATA_CONSTRUCT {}

NiGeometryData::~NiGeometryData() {}

void NiGeometryData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiGeometryData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiGeometryData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiGeometryData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiGeometryData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiGeometryData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

int NiGeometryData::GetVertexCount() const {
	return int(vertices.size());
}

short NiGeometryData::GetUVSetCount() const {
	return short(uvSets.size());
}

vector<Vector3> NiGeometryData::GetVertices() const {
	return vertices;
}

vector<Vector3> NiGeometryData::GetNormals() const {
	return normals;
}

vector<Color4> NiGeometryData::GetColors() const {
	return vertexColors;
}

vector<TexCoord> NiGeometryData::GetUVSet( int index ) const {
	return uvSets[index];
}

void NiGeometryData::SetUVSetCount(int n) {
	uvSets.resize(n);
	hasUv = ( uvSets.size() != 0 );
}

//--Setters--//
void NiGeometryData::SetVertices( const vector<Vector3> & in ) {
	vertices = in;
	hasVertices = ( vertices.size() != 0 );

	//Clear out all other data as it is now based on old vertex information
	normals.clear();
	hasNormals = false;
	vertexColors.clear();
	this->hasVertexColors = false;
	for (unsigned int i = 0; i < uvSets.size(); ++i ) {
		uvSets[i].clear();
	}

	//If any vertices were given, calculate the new center and radius
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

void NiGeometryData::SetNormals( const vector<Vector3> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.");
	normals = in;
	hasNormals = ( normals.size() != 0 );
}

void NiGeometryData::SetVertexColors( const vector<Color4> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.");
	vertexColors = in;
	hasVertexColors = ( vertexColors.size() != 0 );
}

void NiGeometryData::SetUVSet( int index, const vector<TexCoord> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Vector size must equal Vertex Count.");
	uvSets[index] = in;
}

Vector3 NiGeometryData::GetCenter() const {
	return center;
}

float NiGeometryData::GetRadius() const {
	return radius;
}

void NiGeometryData::Transform( const Matrix44 & transform ) {
	Matrix44 rotation = Matrix44( transform.GetRotation() );

	//Apply the transformations
	for ( unsigned int i = 0; i < vertices.size(); ++i ) {
		vertices[i] = transform * vertices[i];
	}
	for ( unsigned int i = 0; i < normals.size(); ++i ) {
		normals[i] = rotation * normals[i];
	}
}

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiGeometryData"] = NiGeometryData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiGeometryData::Create() {
	return new NiGeometryData;
}
