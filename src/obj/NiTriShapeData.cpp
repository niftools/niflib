/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiTriShapeData.h"
#include "../../include/gen/MatchGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriShapeData::TYPE("NiTriShapeData", &NI_TRI_SHAPE_DATA_PARENT::TYPE );

NiTriShapeData::NiTriShapeData() NI_TRI_SHAPE_DATA_CONSTRUCT {}

NiTriShapeData::~NiTriShapeData() {}

void NiTriShapeData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTriShapeData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTriShapeData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTriShapeData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTriShapeData::GetRefs() const {
	return InternalGetRefs();
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

	for ( unsigned int i = 0; i < matchGroups.size(); ++i ){
		// Find all vertices that match this one.
		for ( unsigned short j = 0; j < vertices.size(); ++j ) {
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
	//Remove any bad triangles
	vector<Triangle> good_triangles;
	for ( unsigned i = 0; i < triangles.size(); ++i ) {
		const Triangle & t = triangles[i];
		if ( t.v1 != t.v2 && t.v2 != t.v3 && t.v1 != t.v3 ) {
			good_triangles.push_back(t);
		}
	}
	return good_triangles;
}

void NiTriShapeData::SetTriangles( const vector<Triangle> & in ) {
	if ( in.size() > 65535 || in.size() < 0 ) {
		throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
	}

	triangles = in;

	hasTriangles = ( triangles.size() != 0 );

	//Set nuber of triangles
	numTriangles = (unsigned int)(triangles.size());

	//Set number of trianble points to the number of triangles times 3
	numTrianglePoints = numTriangles * 3;
}

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiTriShapeData"] = NiTriShapeData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiTriShapeData::Create() {
	return new NiTriShapeData;
}
