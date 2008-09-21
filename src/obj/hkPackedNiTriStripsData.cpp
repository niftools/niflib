/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
#include "../../include/gen/hkTriangle.h"
using namespace Niflib;

//Definition of TYPE constant
const Type hkPackedNiTriStripsData::TYPE("hkPackedNiTriStripsData", &bhkShapeCollection::TYPE );

hkPackedNiTriStripsData::hkPackedNiTriStripsData() : numTriangles((unsigned int)0), numVertices((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

hkPackedNiTriStripsData::~hkPackedNiTriStripsData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & hkPackedNiTriStripsData::GetType() const {
	return TYPE;
}

NiObject * hkPackedNiTriStripsData::Create() {
	return new hkPackedNiTriStripsData;
}

void hkPackedNiTriStripsData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Read( in, link_stack, info );
	NifStream( numTriangles, in, info );
	triangles.resize(numTriangles);
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, in, info );
		NifStream( triangles[i1].unknownShort, in, info );
		NifStream( triangles[i1].normal, in, info );
	};
	NifStream( numVertices, in, info );
	vertices.resize(numVertices);
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void hkPackedNiTriStripsData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Write( out, link_map, info );
	numVertices = (unsigned int)(vertices.size());
	numTriangles = (unsigned int)(triangles.size());
	NifStream( numTriangles, out, info );
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, out, info );
		NifStream( triangles[i1].unknownShort, out, info );
		NifStream( triangles[i1].normal, out, info );
	};
	NifStream( numVertices, out, info );
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string hkPackedNiTriStripsData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapeCollection::asString();
	numVertices = (unsigned int)(vertices.size());
	numTriangles = (unsigned int)(triangles.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Triangle:  " << triangles[i1].triangle << endl;
		out << "    Unknown Short:  " << triangles[i1].unknownShort << endl;
		out << "    Normal:  " << triangles[i1].normal << endl;
	};
	out << "  Num Vertices:  " << numVertices << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void hkPackedNiTriStripsData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> hkPackedNiTriStripsData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapeCollection::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

vector<Triangle> hkPackedNiTriStripsData::GetTriangles() const {
	//Remove any bad triangles
	vector<Triangle> good_triangles;
	for ( unsigned i = 0; i < triangles.size(); ++i ) {
		const Triangle & t = triangles[i].triangle;
		if ( t.v1 != t.v2 && t.v2 != t.v3 && t.v1 != t.v3 ) {
			good_triangles.push_back(t);
		}
	}
	return good_triangles;
}

vector<Vector3> hkPackedNiTriStripsData::GetNormals() const {
	//Remove any bad triangles
	vector<Vector3> good_normals;
	for ( unsigned i = 0; i < triangles.size(); ++i ) {
		const Vector3 & t = triangles[i].normal;
		good_normals.push_back(t);
	}
	return good_normals;
}

int hkPackedNiTriStripsData::GetVertexCount() const {
	return int(vertices.size());
}

vector<Vector3> hkPackedNiTriStripsData::GetVertices() const {
	return vertices;
}

int hkPackedNiTriStripsData::GetNumFace( ) const {
	return int(triangles.size());
}

void hkPackedNiTriStripsData::SetNumFaces( int value ) {
	if ( value > 65535 || value < 0 ) {
		throw runtime_error("Invalid Face Count: must be between 0 and 65535.");
	}
	triangles.resize(value);
}

void hkPackedNiTriStripsData::SetTriangles( const vector<Triangle> & in ) {
	if ( triangles.size() != in.size()) {
		throw runtime_error("Invalid Face Count: triangle count must be same as face count.");
	}
	for (size_t i=0; i<triangles.size(); ++i) {
		triangles[i].triangle = in[i];
	}
}

void hkPackedNiTriStripsData::SetNormals( const vector<Vector3> & in ) {
	if ( triangles.size() != in.size()) {
		throw runtime_error("Invalid Face Count: normal count must be same as face count.");
	}
	for (size_t i=0; i<triangles.size(); ++i) {
		triangles[i].normal = in[i];
	}
}

void hkPackedNiTriStripsData::SetVertices( const vector<Vector3> & in ) {
	if ( in.size() > 65535 || in.size() < 0 ) {
		throw runtime_error("Invalid Vertex Count: must be between 0 and 65535.");
	}
	vertices = in;
}

//--END CUSTOM CODE--//
