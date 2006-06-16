/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriStripsData.h"

//Definition of TYPE constant
const Type NiTriStripsData::TYPE("NiTriStripsData", &NI_TRI_STRIPS_DATA_PARENT::TypeConst() );

NiTriStripsData::NiTriStripsData() NI_TRI_STRIPS_DATA_CONSTRUCT {}

NiTriStripsData::~NiTriStripsData() {}

void NiTriStripsData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_STRIPS_DATA_READ
}

void NiTriStripsData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRI_STRIPS_DATA_WRITE
}

string NiTriStripsData::asString( bool verbose ) const {
	NI_TRI_STRIPS_DATA_STRING
}

void NiTriStripsData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_STRIPS_DATA_FIXLINKS
}

list<NiObjectRef> NiTriStripsData::GetRefs() const {
	NI_TRI_STRIPS_DATA_GETREFS
}

const Type & NiTriStripsData::GetType() const {
	return TYPE;
};

ushort NiTriStripsData::GetStripCount() const {
	return ushort(points.size());
}

void NiTriStripsData::SetStripCount(int n) {
	points.resize( n );

	//Recalculate Triangle Count
	numTriangles = CalcTriangleCount();
}

//Getters
vector<ushort> NiTriStripsData::GetStrip( int index ) const {
	return points[index];
}

vector<Triangle> NiTriStripsData::GetTriangles() const {

	//Create a vector to hold the triangles
	vector<Triangle> triangles( numTriangles );
	int n = 0; // Current triangle

	//Cycle through all strips
	vector< vector<ushort> >::const_iterator it;
	for (it = points.begin(); it != points.end(); ++it ) {
		//The first three values in the strip are the first triangle
		triangles[n].Set( (*it)[0], (*it)[1], (*it)[2] );

		//Move to the next triangle
		++n;

		//The remaining triangles use the previous two indices as their first two indices.
		for( uint i = 3; i < it->size(); ++i ) {
			//Odd numbered triangles need to be reversed to keep the vertices in counter-clockwise order
			if ( i % 2 == 0 ) {
				//cout << (*it)[i - 2] << ", " << (*it)[i - 1] << ", " << (*it)[i] << endl;
				triangles[n].Set( (*it)[i - 2], (*it)[i - 1], (*it)[i] );
			} else {
				//cout << (*it)[i] << ", " << (*it)[i - 1] << ", " << (*it)[i - 2] << endl;
				triangles[n].Set( (*it)[i], (*it)[i - 1], (*it)[i - 2] );
			}

			//Move to the next triangle
			++n;
		}
	}

	return triangles;
}

//Setter
void NiTriStripsData::SetStrip( int index, const vector<ushort> & in ) {
	points[index] = in;

	//Recalculate Triangle Count
	numTriangles = CalcTriangleCount();
}

ushort NiTriStripsData::CalcTriangleCount() const {

	//Calculate number of triangles
	//Sum of length of each strip - 2
	ushort numTriangles = 0;
	for ( uint i = 0; i < points.size(); ++i ) {
		numTriangles += ushort(points[i].size() - 2);
	}

	return numTriangles;
}

