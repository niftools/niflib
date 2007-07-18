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
#include "../../include/obj/NiGeometryData.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiGeometryData::TYPE("NiGeometryData", &NiObject::TYPE );

NiGeometryData::NiGeometryData() : numVertices((unsigned short)0), unknownShort1((unsigned short)0), hasVertices(1), numUvSets((unsigned short)0), hasNormals(false), radius(0.0f), hasVertexColors(false), hasUv(false), consistencyFlags((ConsistencyType)0), unknownLink1(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiGeometryData::~NiGeometryData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiGeometryData::GetType() const {
	return TYPE;
}

NiObject * NiGeometryData::Create() {
	return new NiGeometryData;
}

void NiGeometryData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( name, in, info );
	};
	NifStream( numVertices, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort1, in, info );
	};
	NifStream( hasVertices, in, info );
	if ( (hasVertices != 0) ) {
		vertices.resize(numVertices);
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], in, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numUvSets, in, info );
	};
	NifStream( hasNormals, in, info );
	if ( (hasNormals != 0) ) {
		normals.resize(numVertices);
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			NifStream( normals[i2], in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (((hasNormals != 0)) && ((numUvSets & 4096))) ) {
			unknownVectors1.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownVectors1.size(); i3++) {
				NifStream( unknownVectors1[i3], in, info );
			};
			unknownVectors2.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownVectors2.size(); i3++) {
				NifStream( unknownVectors2[i3], in, info );
			};
		};
	};
	NifStream( center, in, info );
	NifStream( radius, in, info );
	NifStream( hasVertexColors, in, info );
	if ( (hasVertexColors != 0) ) {
		vertexColors.resize(numVertices);
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			NifStream( vertexColors[i2], in, info );
		};
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( numUvSets, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( hasUv, in, info );
	};
	uvSets.resize((numUvSets & 63));
	for (unsigned int i1 = 0; i1 < uvSets.size(); i1++) {
		uvSets[i1].resize(numVertices);
		for (unsigned int i2 = 0; i2 < uvSets[i1].size(); i2++) {
			NifStream( uvSets[i1][i2], in, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( consistencyFlags, in, info );
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiGeometryData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	numUvSets = (unsigned short)(uvSets.size());
	numVertices = (unsigned short)(vertices.size());
	if ( info.version >= 0x0A020000 ) {
		NifStream( name, out, info );
	};
	NifStream( numVertices, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort1, out, info );
	};
	NifStream( hasVertices, out, info );
	if ( (hasVertices != 0) ) {
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], out, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numUvSets, out, info );
	};
	NifStream( hasNormals, out, info );
	if ( (hasNormals != 0) ) {
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			NifStream( normals[i2], out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (((hasNormals != 0)) && ((numUvSets & 4096))) ) {
			for (unsigned int i3 = 0; i3 < unknownVectors1.size(); i3++) {
				NifStream( unknownVectors1[i3], out, info );
			};
			for (unsigned int i3 = 0; i3 < unknownVectors2.size(); i3++) {
				NifStream( unknownVectors2[i3], out, info );
			};
		};
	};
	NifStream( center, out, info );
	NifStream( radius, out, info );
	NifStream( hasVertexColors, out, info );
	if ( (hasVertexColors != 0) ) {
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			NifStream( vertexColors[i2], out, info );
		};
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( numUvSets, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( hasUv, out, info );
	};
	for (unsigned int i1 = 0; i1 < uvSets.size(); i1++) {
		for (unsigned int i2 = 0; i2 < uvSets[i1].size(); i2++) {
			NifStream( uvSets[i1][i2], out, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( consistencyFlags, out, info );
	};
	if ( info.version >= 0x14000004 ) {
		if ( info.version < VER_3_3_0_13 ) {
			NifStream( (unsigned int)&(*unknownLink1), out, info );
		} else {
			if ( unknownLink1 != NULL ) {
				NifStream( link_map.find( StaticCast<NiObject>(unknownLink1) )->second, out, info );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
			}
		}
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiGeometryData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numUvSets = (unsigned short)(uvSets.size());
	numVertices = (unsigned short)(vertices.size());
	out << "  Name:  " << name << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Has Vertices:  " << hasVertices << endl;
	if ( (hasVertices != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << vertices[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num UV Sets:  " << numUvSets << endl;
	out << "  Has Normals:  " << hasNormals << endl;
	if ( (hasNormals != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Normals[" << i2 << "]:  " << normals[i2] << endl;
			array_output_count++;
		};
	};
	if ( (((hasNormals != 0)) && ((numUvSets & 4096))) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownVectors1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Vectors 1[" << i2 << "]:  " << unknownVectors1[i2] << endl;
			array_output_count++;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownVectors2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Vectors 2[" << i2 << "]:  " << unknownVectors2[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Center:  " << center << endl;
	out << "  Radius:  " << radius << endl;
	out << "  Has Vertex Colors:  " << hasVertexColors << endl;
	if ( (hasVertexColors != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Colors[" << i2 << "]:  " << vertexColors[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has UV:  " << hasUv << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < uvSets.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < uvSets[i1].size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      UV Sets[" << i2 << "]:  " << uvSets[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Consistency Flags:  " << consistencyFlags << endl;
	out << "  Unknown Link 1:  " << unknownLink1 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiGeometryData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x14000004 ) {
		unknownLink1 = FixLink<NiObject>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiGeometryData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( unknownLink1 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink1));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

// Calculate bounding sphere using minimum-volume axis-align bounding box.  Its fast but not a very good fit.
static void CalcAxisAlignedBox(const vector<Vector3>& vertices, Vector3& center, float& radius)
{
	//--Calculate center & radius--//

	//Set lows and highs to first vertex
	Vector3 lows = vertices[ 0 ];
	Vector3 highs = vertices[ 0 ];

	//Iterate through the vertices, adjusting the stored values
	//if a vertex with lower or higher values is found
	for ( unsigned int i = 0; i < vertices.size(); ++i ) {
		const Vector3 & v = vertices[ i ];

		if ( v.x > highs.x ) highs.x = v.x;
		else if ( v.x < lows.x ) lows.x = v.x;

		if ( v.y > highs.y ) highs.y = v.y;
		else if ( v.y < lows.y ) lows.y = v.y;

		if ( v.z > highs.z ) highs.z = v.z;
		else if ( v.z < lows.z ) lows.z = v.z;
	}

	//Now we know the extent of the shape, so the center will be the average
	//of the lows and highs
	center = (highs + lows) / 2.0f;

	//The radius will be the largest distance from the center
	Vector3 diff;
	float dist2(0.0f), maxdist2(0.0f);
	for ( unsigned int i = 0; i < vertices.size(); ++i ) {
		const Vector3 & v = vertices[ i ];

		diff = center - v;
		dist2 = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
		if ( dist2 > maxdist2 ) maxdist2 = dist2;
	};
	radius = sqrt(maxdist2);
}

// Calculate bounding sphere using average position of the points.  Better fit but slower.
static void CalcCenteredSphere(const vector<Vector3>& vertices, Vector3& center, float& radius)
{
	size_t nv = vertices.size();
	Vector3 sum;
	for (size_t i=0; i<nv; ++i)
		sum += vertices[ i ];
	center = sum / float(nv);
	radius = 0.0f;
	for (size_t i=0; i<nv; ++i){
		Vector3 diff = vertices[ i ] - center;
		float mag = diff.Magnitude();
		radius = max(radius, mag);
	}
}

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

ConsistencyType NiGeometryData::GetConsistencyFlags() const {
	return consistencyFlags;
}

void NiGeometryData::SetConsistencyFlags( const ConsistencyType & value ) {
	consistencyFlags = value;
}

//--END CUSTOM CODE--//
